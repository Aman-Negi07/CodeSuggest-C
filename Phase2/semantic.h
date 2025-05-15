/**
 * semantic.h - Semantic Analysis for C Compiler
 * Contains function declarations and data structures for semantic analysis
 */

#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Color definitions (reused from scanner.l)
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Maximum scope nesting level
#define MAX_SCOPE_DEPTH 100

// Data structure to track scopes
typedef struct {
    int level;                // Current scope level
    int scope_stack[MAX_SCOPE_DEPTH]; // Stack of scope IDs
    int current_scope;        // Current scope ID
    int next_scope_id;        // Next available scope ID
} ScopeTracker;

// Data structure for semantic error tracking
typedef struct {
    char message[200];
    int line_number;
} SemanticError;

// Function declarations
void initializeSemanticAnalyzer();
void enterScope();
void exitScope();
int getCurrentScope();

// Symbol table semantic functions
int checkVariableDeclaration(char *name);
void checkVariableRedeclaration(char *name);
void checkUndeclaredVariable(char *name);
int checkCompatibleTypes(char *type1, char *type2);
int getTypeFromSymbolTable(char *name);
void performTypeChecking(char *left, char *right, char *operator);
int validateArrayAccess(char *name, char *index_expr);
void checkFunctionCall(char *name, int param_count);
void validateReturnType(char *func_type, char *return_type);

// Error reporting functions
void semanticError(char *message, int line_number);
void printSemanticErrors();
int getSemanticErrorCount();

// Analysis control functions
void performSemanticAnalysis();
void printSemanticAnalysisReport();

extern ScopeTracker scope;
extern SemanticError errors[100];
extern int error_count;

#endif // SEMANTIC_H 