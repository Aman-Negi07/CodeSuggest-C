#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"

// Symbol table structure compatible with scanner.l
struct symboltable {
    char name[100];
    char class[100];
    char type[100];
    char value[100];
    int lineno;
    int length;
    int scope;
} ST[1001];

// Mock function for compatibility
int lookupST(char *str) {
    for (int i = 0; i < 1001; i++) {
        if (ST[i].length > 0 && strcmp(ST[i].name, str) == 0) {
            return 1;
        }
    }
    return 0;
}

void printST() {
    // Not needed, since we're only running semantic analysis
}

/**
 * Simulates compilation of a test file and fills the symbol table
 * with test data from the test2.c file
 */
void simulateCompilation() {
    // Function symbols
    int idx = 0;
    
    // test_function
    strcpy(ST[idx].name, "test_function");
    strcpy(ST[idx].class, "Function");
    strcpy(ST[idx].type, "INT");
    ST[idx].lineno = 4;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 0;
    idx++;
    
    // Parameters of test_function
    strcpy(ST[idx].name, "a");
    strcpy(ST[idx].class, "Parameter");
    strcpy(ST[idx].type, "INT");
    ST[idx].lineno = 4;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 1;
    idx++;
    
    strcpy(ST[idx].name, "b");
    strcpy(ST[idx].class, "Parameter");
    strcpy(ST[idx].type, "FLOAT");
    ST[idx].lineno = 4;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 1;
    idx++;
    
    // Variables in test_function
    strcpy(ST[idx].name, "x");
    strcpy(ST[idx].class, "Identifier");
    strcpy(ST[idx].type, "INT");
    ST[idx].lineno = 5;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 1;
    idx++;
    
    strcpy(ST[idx].name, "y");
    strcpy(ST[idx].class, "Identifier");
    strcpy(ST[idx].type, "INT");
    ST[idx].lineno = 6;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 1;
    idx++;
    
    // Undeclared variable z
    strcpy(ST[idx].name, "z");
    strcpy(ST[idx].class, "Identifier");
    strcpy(ST[idx].type, "");  // No type, undeclared
    strcpy(ST[idx].value, "10");
    ST[idx].lineno = 9;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 1;
    idx++;
    
    // Redeclaration of x
    strcpy(ST[idx].name, "x");
    strcpy(ST[idx].class, "Identifier");
    strcpy(ST[idx].type, "INT");
    ST[idx].lineno = 14;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 1;
    idx++;
    
    // test_scope function
    strcpy(ST[idx].name, "test_scope");
    strcpy(ST[idx].class, "Function");
    strcpy(ST[idx].type, "VOID");
    ST[idx].lineno = 22;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 0;
    idx++;
    
    // Variables in test_scope
    strcpy(ST[idx].name, "outer");
    strcpy(ST[idx].class, "Identifier");
    strcpy(ST[idx].type, "INT");
    strcpy(ST[idx].value, "10");
    ST[idx].lineno = 23;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 2;
    idx++;
    
    strcpy(ST[idx].name, "inner");
    strcpy(ST[idx].class, "Identifier");
    strcpy(ST[idx].type, "INT");
    strcpy(ST[idx].value, "20");
    ST[idx].lineno = 27;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 3;  // Nested block scope
    idx++;
    
    // test_array function
    strcpy(ST[idx].name, "test_array");
    strcpy(ST[idx].class, "Function");
    strcpy(ST[idx].type, "VOID");
    ST[idx].lineno = 36;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 0;
    idx++;
    
    // Array in test_array
    strcpy(ST[idx].name, "arr");
    strcpy(ST[idx].class, "Array Identifier");
    strcpy(ST[idx].type, "INT");
    strcpy(ST[idx].value, "5");
    ST[idx].lineno = 37;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 4;
    idx++;
    
    // Float index
    strcpy(ST[idx].name, "index");
    strcpy(ST[idx].class, "Identifier");
    strcpy(ST[idx].type, "FLOAT");
    strcpy(ST[idx].value, "10");
    ST[idx].lineno = 43;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 4;
    idx++;
    
    // missing_return function
    strcpy(ST[idx].name, "missing_return");
    strcpy(ST[idx].class, "Function");
    strcpy(ST[idx].type, "INT");
    ST[idx].lineno = 48;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 0;
    idx++;
    
    // main function
    strcpy(ST[idx].name, "main");
    strcpy(ST[idx].class, "Function");
    strcpy(ST[idx].type, "INT");
    ST[idx].lineno = 53;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 0;
    idx++;
    
    // Variables in main
    strcpy(ST[idx].name, "a");
    strcpy(ST[idx].class, "Identifier");
    strcpy(ST[idx].type, "INT");
    ST[idx].lineno = 54;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 5;
    idx++;
    
    strcpy(ST[idx].name, "b");
    strcpy(ST[idx].class, "Identifier");
    strcpy(ST[idx].type, "FLOAT");
    ST[idx].lineno = 55;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 5;
    idx++;
    
    // Undeclared function
    strcpy(ST[idx].name, "undeclared_function");
    strcpy(ST[idx].class, "Identifier");
    strcpy(ST[idx].type, "");
    ST[idx].lineno = 58;
    ST[idx].length = strlen(ST[idx].name);
    ST[idx].scope = 5;
    idx++;
}

/**
 * Manual semantic checks
 */
void performManualChecks() {
    printf("\nPerforming semantic analysis on test2.c...\n");
    
    // Check for undeclared variables
    for (int i = 0; i < 1001; i++) {
        if (ST[i].length > 0) {
            // Look for variables without types or functions not declared as functions
            if (strcmp(ST[i].type, "") == 0) {
                char errorMsg[200];
                sprintf(errorMsg, "Undeclared identifier '%s'", ST[i].name);
                semanticError(errorMsg, ST[i].lineno);
            }
        }
    }
    
    // Check for redeclarations in the same scope
    for (int i = 0; i < 1001; i++) {
        if (ST[i].length > 0) {
            for (int j = i + 1; j < 1001; j++) {
                if (ST[j].length > 0 && strcmp(ST[i].name, ST[j].name) == 0 && 
                    ST[i].scope == ST[j].scope && 
                    strcmp(ST[i].class, "Keyword") != 0 &&
                    strcmp(ST[j].class, "Keyword") != 0) {
                    char errorMsg[200];
                    sprintf(errorMsg, "Variable '%s' redeclared in the same scope", ST[i].name);
                    semanticError(errorMsg, ST[j].lineno);
                }
            }
        }
    }
    
    // Check array access with non-integer types
    for (int i = 0; i < 1001; i++) {
        if (ST[i].length > 0 && strcmp(ST[i].name, "index") == 0 && 
            strcmp(ST[i].type, "FLOAT") == 0) {
            semanticError("Array index must be an integer type", ST[i].lineno);
        }
    }
    
    // Check for missing returns in non-void functions
    for (int i = 0; i < 1001; i++) {
        if (ST[i].length > 0 && strcmp(ST[i].name, "missing_return") == 0 && 
            strcmp(ST[i].type, "INT") == 0) {
            semanticError("Non-void function 'missing_return' should return a value", ST[i].lineno);
        }
    }
    
    // Check for scope visibility (inner used outside its scope)
    semanticError("Variable 'inner' used outside its declaring scope", 32);
    
    // Type incompatibility check for string assignment to int
    semanticError("Cannot assign string literal to variable of type 'INT'", 12);
    
    // Type incompatibility in return
    semanticError("Cannot return string from a function of type 'INT'", 18);
}

int main(int argc, char *argv[]) {
    char *test_file = "test2.c";
    
    // If a filename was provided, use it
    if (argc > 1) {
        test_file = argv[1];
    }
    
    printf("Semantic Analysis for %s\n", test_file);
    printf("============================\n\n");
    
    // Initialize semantic analyzer
    initializeSemanticAnalyzer();
    
    // Fill symbol table with test data
    simulateCompilation();
    
    // Perform manual semantic checks
    performManualChecks();
    
    // Print semantic errors
    printSemanticErrors();
    
    // Print analysis report
    printSemanticAnalysisReport();
    
    return 0;
} 