/**
 * semantic.c - Semantic Analysis Implementation
 * Implements semantic analysis for C compiler
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./parser.tab.h"
#include "semantic.h"

// External symbol table structures from scanner.l
extern struct symboltable {
    char name[100];
    char class[100];
    char type[100];
    char value[100];
    int lineno;
    int length;
    int scope;  // Adding scope to symbol table
} ST[1001];

extern int lookupST(char *str);
extern void printST();

// Global variables
ScopeTracker scope;
SemanticError errors[100];
int error_count = 0;
int semantic_check_enabled = 1;

// Internal helper functions
int isNumericType(char *type);
int isIntegerType(char *type);
int isFloatingType(char *type);
char* getBaseType(char *type);

/**
 * Initialize the semantic analyzer
 */
void initializeSemanticAnalyzer() {
    // Initialize scope
    scope.level = 0;
    scope.current_scope = 0;
    scope.next_scope_id = 1;
    scope.scope_stack[0] = 0;
    
    // Reset error count
    error_count = 0;
    
    printf(ANSI_COLOR_CYAN "Initializing Semantic Analysis..." ANSI_COLOR_RESET "\n");
    printf("Debug: semantic_check_enabled = %d\n", semantic_check_enabled);
}

/**
 * Enter a new scope (e.g., function or block)
 */
void enterScope() {
    scope.level++;
    if (scope.level >= MAX_SCOPE_DEPTH) {
        semanticError("Maximum scope depth exceeded", -1);
        return;
    }
    
    // Assign a new scope ID
    scope.current_scope = scope.next_scope_id++;
    scope.scope_stack[scope.level] = scope.current_scope;
    printf("Debug: Entered scope %d at level %d\n", scope.current_scope, scope.level);
}

/**
 * Exit current scope
 */
void exitScope() {
    if (scope.level > 0) {
        int old_scope = scope.current_scope;
        scope.level--;
        scope.current_scope = scope.scope_stack[scope.level];
        printf("Debug: Exited scope %d to scope %d at level %d\n", old_scope, scope.current_scope, scope.level);
    }
}

/**
 * Get current scope ID
 */
int getCurrentScope() {
    return scope.current_scope;
}

/**
 * Add semantic error
 */
void semanticError(char *message, int line_number) {
    printf("Debug: Adding semantic error: %s (line %d)\n", message, line_number);
    if (error_count < 100) {
        strcpy(errors[error_count].message, message);
        errors[error_count].line_number = line_number;
        error_count++;
    }
}

/**
 * Print all semantic errors
 */
void printSemanticErrors() {
    printf("Debug: Printing %d semantic errors\n", error_count);
    if (error_count == 0) {
        printf(ANSI_COLOR_GREEN "No semantic errors detected." ANSI_COLOR_RESET "\n");
        return;
    }
    
    printf(ANSI_COLOR_RED "\nSemantic Errors:" ANSI_COLOR_RESET "\n");
    printf("------------------\n");
    
    for (int i = 0; i < error_count; i++) {
        if (errors[i].line_number > 0) {
            printf(ANSI_COLOR_RED "Line %d: %s" ANSI_COLOR_RESET "\n", 
                  errors[i].line_number, errors[i].message);
        } else {
            printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET "\n", errors[i].message);
        }
    }
}

/**
 * Get total semantic error count
 */
int getSemanticErrorCount() {
    return error_count;
}

/**
 * Check if a variable has been declared
 */
int checkVariableDeclaration(char *name) {
    if (!semantic_check_enabled) return 1;
    
    for (int i = 0; i < 1001; i++) {
        if (ST[i].length > 0 && strcmp(ST[i].name, name) == 0) {
            // Check if in current or parent scope
            if (ST[i].scope <= scope.current_scope) {
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Check if variable is already declared in current scope
 */
void checkVariableRedeclaration(char *name) {
    if (!semantic_check_enabled) return;
    
    for (int i = 0; i < 1001; i++) {
        if (ST[i].length > 0 && strcmp(ST[i].name, name) == 0) {
            // Check if in current scope
            if (ST[i].scope == scope.current_scope) {
                char errorMsg[200];
                sprintf(errorMsg, "Variable '%s' already declared in this scope", name);
                semanticError(errorMsg, ST[i].lineno);
                return;
            }
        }
    }
}

/**
 * Check if a variable has been declared before use
 */
void checkUndeclaredVariable(char *name) {
    if (!semantic_check_enabled) return;
    
    if (!checkVariableDeclaration(name)) {
        char errorMsg[200];
        sprintf(errorMsg, "Undeclared variable '%s'", name);
        semanticError(errorMsg, -1);
    }
}

/**
 * Check if two types are compatible
 */
int checkCompatibleTypes(char *type1, char *type2) {
    if (!semantic_check_enabled) return 1;
    
    // If they're the exact same type, they're compatible
    if (strcmp(type1, type2) == 0) {
        return 1;
    }
    
    // Check numeric types compatibility
    if (isNumericType(type1) && isNumericType(type2)) {
        return 1;
    }
    
    return 0;
}

/**
 * Get the type of a variable from the symbol table
 */
int getTypeFromSymbolTable(char *name) {
    for (int i = 0; i < 1001; i++) {
        if (ST[i].length > 0 && strcmp(ST[i].name, name) == 0) {
            if (strcmp(ST[i].type, "INT") == 0) return INT;
            if (strcmp(ST[i].type, "CHAR") == 0) return CHAR;
            if (strcmp(ST[i].type, "FLOAT") == 0) return FLOAT;
            if (strcmp(ST[i].type, "DOUBLE") == 0) return DOUBLE;
            if (strcmp(ST[i].type, "VOID") == 0) return VOID;
            // Add more types as needed
        }
    }
    return -1; // Type not found
}

/**
 * Perform type checking for binary operations
 */
void performTypeChecking(char *left, char *right, char *operator) {
    if (!semantic_check_enabled) return;
    
    checkUndeclaredVariable(left);
    checkUndeclaredVariable(right);
    
    char *left_type = NULL;
    char *right_type = NULL;
    
    // Get the types from symbol table
    for (int i = 0; i < 1001; i++) {
        if (ST[i].length > 0) {
            if (strcmp(ST[i].name, left) == 0) {
                left_type = ST[i].type;
            }
            if (strcmp(ST[i].name, right) == 0) {
                right_type = ST[i].type;
            }
        }
    }
    
    // If we couldn't find the types, exit
    if (!left_type || !right_type) return;
    
    // Check type compatibility
    if (!checkCompatibleTypes(left_type, right_type)) {
        char errorMsg[500]; // Increased buffer size
        sprintf(errorMsg, "Incompatible types for operation '%s': %s and %s", 
                operator, left_type, right_type);
        semanticError(errorMsg, -1);
    }
}

/**
 * Validate array access
 */
int validateArrayAccess(char *name, char *index_expr) {
    if (!semantic_check_enabled) return 1;
    
    // First check if variable exists
    checkUndeclaredVariable(name);
    
    // Then check if index is numeric
    if (checkVariableDeclaration(index_expr)) {
        char *index_type = NULL;
        
        // Get index type from symbol table
        for (int i = 0; i < 1001; i++) {
            if (ST[i].length > 0 && strcmp(ST[i].name, index_expr) == 0) {
                index_type = ST[i].type;
                break;
            }
        }
        
        if (index_type && !isIntegerType(index_type)) {
            char errorMsg[200];
            sprintf(errorMsg, "Array index for '%s' must be an integer type", name);
            semanticError(errorMsg, -1);
            return 0;
        }
    }
    
    return 1;
}

/**
 * Check function call
 */
void checkFunctionCall(char *name, int param_count) {
    if (!semantic_check_enabled) return;
    
    // Check if function is declared
    int found = 0;
    for (int i = 0; i < 1001; i++) {
        if (ST[i].length > 0 && strcmp(ST[i].name, name) == 0 && 
            strcmp(ST[i].class, "Function") == 0) {
            found = 1;
            break;
        }
    }
    
    if (!found) {
        char errorMsg[200];
        sprintf(errorMsg, "Undefined function '%s'", name);
        semanticError(errorMsg, -1);
    }
    
    // Parameter count check would require more information about function definitions
}

/**
 * Validate return type
 */
void validateReturnType(char *func_type, char *return_type) {
    if (!semantic_check_enabled) return;
    
    if (!checkCompatibleTypes(func_type, return_type)) {
        char errorMsg[200];
        sprintf(errorMsg, "Return type '%s' doesn't match function type '%s'", 
                return_type, func_type);
        semanticError(errorMsg, -1);
    }
}

/**
 * Run semantic analysis
 */
void performSemanticAnalysis() {
    printf(ANSI_COLOR_CYAN "Performing Semantic Analysis..." ANSI_COLOR_RESET "\n");
    
    // We'll add specific semantic checks during parsing
    
    // Print any errors
    printSemanticErrors();
}

/**
 * Print semantic analysis report
 */
void printSemanticAnalysisReport() {
    printf("\n%30s" ANSI_COLOR_CYAN "SEMANTIC ANALYSIS REPORT" ANSI_COLOR_RESET "\n", " ");
    printf("%30s %s\n", " ", "-----------------------");
    
    // Print scopes and variables
    printf("\n%30s" ANSI_COLOR_CYAN "VARIABLES BY SCOPE" ANSI_COLOR_RESET "\n", " ");
    
    for (int scope_id = 0; scope_id < scope.next_scope_id; scope_id++) {
        printf("\nScope %d:\n", scope_id);
        printf("%-15s %-10s %-10s\n", "Name", "Type", "Line");
        printf("---------------------------------------\n");
        
        int found = 0;
        for (int i = 0; i < 1001; i++) {
            if (ST[i].length > 0 && ST[i].scope == scope_id) {
                printf("%-15s %-10s %-10d\n", ST[i].name, ST[i].type, ST[i].lineno);
                found = 1;
            }
        }
        
        if (!found) {
            printf("(No variables in this scope)\n");
        }
    }
    
    // Print error summary
    if (error_count > 0) {
        printf("\n%30s" ANSI_COLOR_RED "SEMANTIC ERRORS: %d" ANSI_COLOR_RESET "\n", " ", error_count);
    } else {
        printf("\n%30s" ANSI_COLOR_GREEN "SEMANTIC ANALYSIS SUCCESSFUL" ANSI_COLOR_RESET "\n", " ");
    }
}

/**
 * Helper function to check if type is numeric
 */
int isNumericType(char *type) {
    return (isIntegerType(type) || isFloatingType(type));
}

/**
 * Helper function to check if type is integer
 */
int isIntegerType(char *type) {
    return (strcmp(type, "INT") == 0 || strcmp(type, "LONG") == 0 || 
            strcmp(type, "SHORT") == 0 || strcmp(type, "CHAR") == 0);
}

/**
 * Helper function to check if type is floating point
 */
int isFloatingType(char *type) {
    return (strcmp(type, "FLOAT") == 0 || strcmp(type, "DOUBLE") == 0);
}

/**
 * Get base type from qualified type
 */
char* getBaseType(char *type) {
    // For simple implementation, we return the type as is
    // A more complex implementation would handle type qualifiers
    return type;
} 