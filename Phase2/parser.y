%{
	void yyerror(char* s);
	int yylex();
	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	#include "./semantic.h"  // Include semantic analysis header
	void ins();
	void insV();
	int flag=0;

	#define ANSI_COLOR_RED		"\x1b[31m"
	#define ANSI_COLOR_GREEN	"\x1b[32m"
	#define ANSI_COLOR_CYAN		"\x1b[36m"
	#define ANSI_COLOR_RESET	"\x1b[0m"

	extern char curid[20];
	extern char curtype[20];
	extern char curval[20];
	
	// Symbol table structure from scanner.l
	extern struct symboltable {
		char name[100];
		char class[100];
		char type[100];
		char value[100];
		int lineno;
		int length;
		int scope;
	} ST[1001];
	
	// Current function for return type checking
	char current_function[100];
	char current_function_type[100];
	
	// Variable to store expression type
	char expression_type[100];

%}

%nonassoc IF
%token INT CHAR FLOAT DOUBLE LONG SHORT SIGNED UNSIGNED STRUCT
%token RETURN MAIN
%token VOID
%token WHILE FOR DO 
%token BREAK
%token ENDIF
%expect 2

%token identifier
%token integer_constant string_constant float_constant character_constant

%nonassoc ELSE

%right leftshift_assignment_operator rightshift_assignment_operator
%right XOR_assignment_operator OR_assignment_operator
%right AND_assignment_operator modulo_assignment_operator
%right multiplication_assignment_operator division_assignment_operator
%right addition_assignment_operator subtraction_assignment_operator
%right assignment_operator

%left OR_operator
%left AND_operator
%left pipe_operator
%left caret_operator
%left amp_operator
%left equality_operator inequality_operator
%left lessthan_assignment_operator lessthan_operator greaterthan_assignment_operator greaterthan_operator
%left leftshift_operator rightshift_operator 
%left add_operator subtract_operator
%left multiplication_operator division_operator modulo_operator

%right SIZEOF
%right tilde_operator exclamation_operator
%left increment_operator decrement_operator 


%start program

%%
program
			: declaration_list;

declaration_list
			: declaration D 

D
			: declaration_list
			| ;

declaration
			: variable_declaration 
			| function_declaration
			| structure_definition;

variable_declaration
			: type_specifier variable_declaration_list ';' 
			| structure_declaration;

variable_declaration_list
			: variable_declaration_identifier V;

V
			: ',' variable_declaration_list 
			| ;

variable_declaration_identifier 
			: identifier { 
			    ins(); 
			    // Add scope to symbol table
			    for (int i = 0; i < 1001; i++) {
			        if (ST[i].length > 0 && strcmp(ST[i].name, curid) == 0) {
			            ST[i].scope = getCurrentScope();
			            break;
			        }
			    }
			    // Check for redeclaration
			    checkVariableRedeclaration(curid);
			} vdi;

vdi : identifier_array_type | assignment_operator expression ; 

identifier_array_type
			: '[' initilization_params
			| ;

initilization_params
			: integer_constant ']' initilization
			| ']' string_initilization;

initilization
			: string_initilization
			| array_initialization
			| ;

type_specifier 
			: INT | CHAR | FLOAT | DOUBLE 
			| LONG long_grammar 
			| SHORT short_grammar
			| UNSIGNED unsigned_grammar 
			| SIGNED signed_grammar
			| VOID ;

unsigned_grammar 
			: INT | LONG long_grammar | SHORT short_grammar | ;

signed_grammar 
			: INT | LONG long_grammar | SHORT short_grammar | ;

long_grammar 
			: INT | ;

short_grammar 
			: INT | ;

structure_definition
			: STRUCT identifier { ins(); } '{' { enterScope(); } V1  '}' { exitScope(); } ';';

V1 : variable_declaration V1 | ;

structure_declaration 
			: STRUCT identifier variable_declaration_list;


function_declaration
			: function_declaration_type function_declaration_param_statement;

function_declaration_type
			: type_specifier identifier '(' { 
			    // Store function name and type for return type checking
			    strcpy(current_function, curid);
			    strcpy(current_function_type, curtype);
			    ins(); 
			    for (int i = 0; i < 1001; i++) {
			        if (ST[i].length > 0 && strcmp(ST[i].name, curid) == 0) {
			            strcpy(ST[i].class, "Function");
			            break;
			        }
			    }
			    // Create a new scope for function
			    enterScope();
			};

function_declaration_param_statement
			: params ')' statement { exitScope(); };

params 
			: parameters_list | ;

parameters_list 
			: type_specifier parameters_identifier_list;

parameters_identifier_list 
			: param_identifier parameters_identifier_list_breakup;

parameters_identifier_list_breakup
			: ',' parameters_list 
			| ;

param_identifier 
			: identifier { 
			    ins(); 
			    // Add scope to parameter
			    for (int i = 0; i < 1001; i++) {
			        if (ST[i].length > 0 && strcmp(ST[i].name, curid) == 0) {
			            ST[i].scope = getCurrentScope();
			            strcpy(ST[i].class, "Parameter");
			            break;
			        }
			    }
			} param_identifier_breakup;

param_identifier_breakup
			: '[' ']'
			| ;

statement 
			: expression_statment | compound_statement 
			| conditional_statements | iterative_statements 
			| return_statement | break_statement 
			| variable_declaration;

compound_statement 
			: '{' { enterScope(); } statment_list '}' { exitScope(); };

statment_list 
			: statement statment_list 
			| ;

expression_statment 
			: expression ';' 
			| ';' ;

conditional_statements 
			: IF '(' simple_expression ')' statement conditional_statements_breakup;

conditional_statements_breakup
			: ELSE statement
			| ;

iterative_statements 
			: WHILE '(' simple_expression ')' statement 
			| FOR '(' expression ';' simple_expression ';' expression ')' statement
			| DO statement WHILE '(' simple_expression ')' ';';

return_statement 
			: RETURN return_statement_breakup;

return_statement_breakup
			: ';' { 
			    // Check if return type is compatible with function type
			    if (strcmp(current_function_type, "VOID") != 0) {
			        semanticError("Function with non-void return type must return a value", -1);
			    }
			}
			| expression ';' {
			    // Need to validate return type matches function type
			    // For simplicity, assuming expression_type contains the type of last expression
			    validateReturnType(current_function_type, expression_type);
			};

break_statement 
			: BREAK ';' ;

string_initilization
			: assignment_operator string_constant { insV(); };

array_initialization
			: assignment_operator '{' array_int_declarations '}';

array_int_declarations
			: integer_constant array_int_declarations_breakup;

array_int_declarations_breakup
			: ',' array_int_declarations 
			| ;

expression 
			: mutable expression_breakup
			| simple_expression {
			    // Store expression type for return type checking
			    // This is simplified; in a real implementation, we would track the type through
			    // the expression tree
			    strcpy(expression_type, "INT"); // Default to INT for simplicity
			};

expression_breakup
			: assignment_operator expression {
			    // Type checking for assignment operations
			    if (curid[0] != '\0') {
			        checkUndeclaredVariable(curid);
			    }
			}
			| addition_assignment_operator expression 
			| subtraction_assignment_operator expression 
			| multiplication_assignment_operator expression 
			| division_assignment_operator expression 
			| modulo_assignment_operator expression 
			| increment_operator 
			| decrement_operator ;

simple_expression 
			: and_expression simple_expression_breakup;

simple_expression_breakup 
			: OR_operator and_expression simple_expression_breakup | ;

and_expression 
			: unary_relation_expression and_expression_breakup;

and_expression_breakup
			: AND_operator unary_relation_expression and_expression_breakup
			| ;

unary_relation_expression 
			: exclamation_operator unary_relation_expression 
			| regular_expression ;

regular_expression 
			: sum_expression regular_expression_breakup;

regular_expression_breakup
			: relational_operators sum_expression {
			    // Type checking for relational operations
			    strcpy(expression_type, "INT"); // Relational operations result in boolean (INT)
			}
			| ;

relational_operators 
			: greaterthan_assignment_operator | lessthan_assignment_operator | greaterthan_operator 
			| lessthan_operator | equality_operator | inequality_operator ;

sum_expression 
			: sum_expression sum_operators term 
			| term ;

sum_operators 
			: add_operator 
			| subtract_operator ;

term
			: term MULOP factor 
			| factor ;

MULOP 
			: multiplication_operator | division_operator | modulo_operator ;

factor 
			: immutable | mutable ;

mutable 
			: identifier {
			    // Check if variable is declared
			    checkUndeclaredVariable(curid);
			    
			    // Get type for expression type tracking
			    for (int i = 0; i < 1001; i++) {
			        if (ST[i].length > 0 && strcmp(ST[i].name, curid) == 0) {
			            strcpy(expression_type, ST[i].type);
			            break;
			        }
			    }
			}
			| mutable mutable_breakup;

mutable_breakup
			: '[' expression ']' {
			    // Validate array access - index must be integer
			    // For simplicity, we don't do full expression type checking
			    if (strcmp(expression_type, "INT") != 0) {
			        semanticError("Array index must be an integer", -1);
			    }
			}
			| '.' identifier;

immutable 
			: '(' expression ')' 
			| call | constant;

call
			: identifier '(' {
			    // Check if function exists
			    checkFunctionCall(curid, 0); // Simplified: not tracking param count
			} arguments ')';

arguments 
			: arguments_list | ;

arguments_list 
			: expression A;

A
			: ',' expression A 
			| ;

constant 
			: integer_constant 	{ insV(); strcpy(expression_type, "INT"); } 
			| string_constant	{ insV(); strcpy(expression_type, "CHAR"); } 
			| float_constant	{ insV(); strcpy(expression_type, "FLOAT"); } 
			| character_constant{ insV(); strcpy(expression_type, "CHAR"); };

%%

extern FILE *yyin;
extern int yylineno;
extern char *yytext;
void insertSTtype(char *,char *);
void insertSTvalue(char *, char *);
void incertCT(char *, char *);
void printST();
void printCT();

int main(int argc , char **argv)
{
	yyin = fopen(argv[1], "r");
	
	// Initialize semantic analyzer
	initializeSemanticAnalyzer();
	
	yyparse();

	if(flag == 0)
	{
		printf(ANSI_COLOR_GREEN "Status: Parsing Complete - Valid" ANSI_COLOR_RESET "\n");
		
		// Perform semantic analysis after successful parsing
		performSemanticAnalysis();
		
		printf("%30s" ANSI_COLOR_CYAN "SYMBOL TABLE" ANSI_COLOR_RESET "\n", " ");
		printf("%30s %s\n", " ", "------------");
		printST();

		printf("\n\n%30s" ANSI_COLOR_CYAN "CONSTANT TABLE" ANSI_COLOR_RESET "\n", " ");
		printf("%30s %s\n", " ", "--------------");
		printCT();
		
		// Print semantic analysis report
		printSemanticAnalysisReport();
	}
}

void yyerror(char *s)
{
	printf("%d %s %s\n", yylineno, s, yytext);
	flag=1;
	printf(ANSI_COLOR_RED "Status: Parsing Failed - Invalid\n" ANSI_COLOR_RESET);
}

void ins()
{
	insertSTtype(curid,curtype);
}

void insV()
{
	insertSTvalue(curid,curval);
}

int yywrap()
{
	return 1;
}