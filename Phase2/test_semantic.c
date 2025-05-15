#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"

// Mock symbol table structure for testing
struct symboltable {
    char name[100];
    char class[100];
    char type[100];
    char value[100];
    int lineno;
    int length;
    int scope;
} ST[1001];

// Mock function
int lookupST(char *str) {
    return 0; // For simplicity
}

void printST() {
    printf("Mock symbol table printed\n");
}

int main() {
    printf("Test Semantic Analyzer\n");
    
    // Initialize the semantic analyzer
    initializeSemanticAnalyzer();
    
    // Setup some test data
    strcpy(ST[0].name, "x");
    strcpy(ST[0].class, "Identifier");
    strcpy(ST[0].type, "INT");
    ST[0].lineno = 10;
    ST[0].length = 1;
    ST[0].scope = 0;
    
    strcpy(ST[1].name, "y");
    strcpy(ST[1].class, "Identifier");
    strcpy(ST[1].type, "FLOAT");
    ST[1].lineno = 11;
    ST[1].length = 1;
    ST[1].scope = 0;
    
    // Test scope functions
    printf("\nTesting scopes:\n");
    printf("Current scope: %d\n", getCurrentScope());
    enterScope();
    printf("After enterScope(): %d\n", getCurrentScope());
    exitScope();
    printf("After exitScope(): %d\n", getCurrentScope());
    
    // Test error reporting
    printf("\nTesting error reporting:\n");
    semanticError("Test error message", 42);
    printSemanticErrors();
    
    // Test variable checks
    printf("\nTesting variable checks:\n");
    printf("checkVariableDeclaration('x'): %d\n", checkVariableDeclaration("x"));
    printf("checkVariableDeclaration('z'): %d\n", checkVariableDeclaration("z"));
    
    // Test type checking
    printf("\nTesting type checking:\n");
    printf("checkCompatibleTypes('INT', 'INT'): %d\n", checkCompatibleTypes("INT", "INT"));
    printf("checkCompatibleTypes('INT', 'FLOAT'): %d\n", checkCompatibleTypes("INT", "FLOAT"));
    printf("checkCompatibleTypes('INT', 'CHAR'): %d\n", checkCompatibleTypes("INT", "CHAR"));
    
    // Print a report
    printf("\nGeneral report:\n");
    printSemanticAnalysisReport();
    
    return 0;
} 