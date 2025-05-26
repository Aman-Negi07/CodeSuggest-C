#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"
#include "parser.h"
#include "suggest.h"

Token tokens[MAX_TOKENS];
int current = 0;

FILE *dotFile;
int nodeId = 0;

Token peek() {
    return tokens[current];
}

int match(TokenType expected, const char *value) {
    if (peek().type == expected && (!value || strcmp(peek().value, value) == 0)) {
        current++;
        return 1;
    }
    return 0;
}

void syntaxError(const char *errorType, const char *message) {
    printf("Syntax Error [%s]: %s at '%s' (line %d)\n", errorType, message, peek().value, peek().line);
    exit(1);
}

int newNode(const char *label) {
    int id = nodeId++;
    fprintf(dotFile, "  node%d [label=\"%s\"];\n", id, label);
    return id;
}

void addEdge(int from, int to) {
    fprintf(dotFile, "  node%d -> node%d;\n", from, to);
}

int tokenNode(Token token) {
    char label[128];
    snprintf(label, sizeof(label), "%s\\n[%s]", token.value, getTokenTypeName(token.type));
    return newNode(label);
}

int expr() {
    int node = newNode("expr");

    if (peek().type == TOKEN_IDENTIFIER || peek().type == TOKEN_NUMBER || peek().type == TOKEN_STRING) {
        addEdge(node, tokenNode(tokens[current]));
        current++;
    } else if (peek().type == TOKEN_LPAREN) {
        addEdge(node, tokenNode(tokens[current]));
        current++;
        addEdge(node, expr());
        if (!match(TOKEN_RPAREN, NULL))
            syntaxError("MissingClosingParenthesis", "Expected ')'");
        addEdge(node, tokenNode(tokens[current - 1]));
    } else {
        syntaxError("InvalidExpressionStart", "Expected identifier, number, or '('");
    }

    while (peek().type == TOKEN_OPERATOR) {
        addEdge(node, tokenNode(tokens[current]));
        current++;
        addEdge(node, expr());
    }

    return node;
}

int decl() {
    int node = newNode("decl");
    if (!(match(TOKEN_KEYWORD, "int") || match(TOKEN_KEYWORD, "float") ||
          match(TOKEN_KEYWORD, "char") || match(TOKEN_KEYWORD, "double") || match(TOKEN_KEYWORD, "void"))) {
        const char *expectedKeywords[] = {"int", "float", "char", "double", "void"};
        suggestKeyword(peek().value, expectedKeywords, 5, peek().line);
        syntaxError("MissingTypeSpecifier", "Expected type specifier");
    }
    addEdge(node, tokenNode(tokens[current - 1]));

    if (!match(TOKEN_IDENTIFIER, NULL))
        syntaxError("MissingIdentifier", "Expected identifier");
    addEdge(node, tokenNode(tokens[current - 1]));

    if (!match(TOKEN_SEMICOLON, NULL))
        syntaxError("MissingSemicolon", "Expected ';'");
    addEdge(node, tokenNode(tokens[current - 1]));

    return node;
}

int stmt() {
    int node = newNode("stmt");

    if (match(TOKEN_IDENTIFIER, NULL)) {
        addEdge(node, tokenNode(tokens[current - 1]));
        if (!match(TOKEN_ASSIGN, NULL))
            syntaxError("MissingAssignmentOperator", "Expected '='");
        addEdge(node, tokenNode(tokens[current - 1]));
        addEdge(node, expr());
        if (!match(TOKEN_SEMICOLON, NULL))
            syntaxError("MissingSemicolon", "Expected ';'");
        addEdge(node, tokenNode(tokens[current - 1]));
    } else if (match(TOKEN_KEYWORD, "return")) {
        addEdge(node, tokenNode(tokens[current - 1]));
        addEdge(node, expr());
        if (!match(TOKEN_SEMICOLON, NULL))
            syntaxError("MissingSemicolon", "Expected ';' after return");
        addEdge(node, tokenNode(tokens[current - 1]));
    } else if (match(TOKEN_KEYWORD, "if")) {
        addEdge(node, tokenNode(tokens[current - 1]));
        if (!match(TOKEN_LPAREN, NULL))
            syntaxError("MissingOpeningParenthesis", "Expected '(' after 'if'");
        addEdge(node, tokenNode(tokens[current - 1]));
        addEdge(node, expr());
        if (!match(TOKEN_RPAREN, NULL))
            syntaxError("MissingClosingParenthesis", "Expected ')' after condition");
        addEdge(node, tokenNode(tokens[current - 1]));
        addEdge(node, block());
        if (match(TOKEN_KEYWORD, "else")) {
            addEdge(node, tokenNode(tokens[current - 1]));
            addEdge(node, block());
        }
    } else if (match(TOKEN_KEYWORD, "while")) {
        addEdge(node, tokenNode(tokens[current - 1]));
        if (!match(TOKEN_LPAREN, NULL))
            syntaxError("MissingOpeningParenthesis", "Expected '(' after 'while'");
        addEdge(node, tokenNode(tokens[current - 1]));
        addEdge(node, expr());
        if (!match(TOKEN_RPAREN, NULL))
            syntaxError("MissingClosingParenthesis", "Expected ')' after condition");
        addEdge(node, tokenNode(tokens[current - 1]));
        addEdge(node, block());
    } else if (match(TOKEN_KEYWORD, "for")) {
        addEdge(node, tokenNode(tokens[current - 1]));
        if (!match(TOKEN_LPAREN, NULL))
            syntaxError("MissingOpeningParenthesis", "Expected '(' after 'for'");
        addEdge(node, tokenNode(tokens[current - 1]));

        if (peek().type == TOKEN_KEYWORD &&
            (strcmp(peek().value, "int") == 0 || strcmp(peek().value, "float") == 0 ||
             strcmp(peek().value, "char") == 0 || strcmp(peek().value, "double") == 0 || strcmp(peek().value, "void") == 0)) {
            addEdge(node, decl());
        } else if (peek().type == TOKEN_IDENTIFIER) {
            addEdge(node, stmt());
        } else if (!match(TOKEN_SEMICOLON, NULL)) {
            syntaxError("MissingForInit", "Expected initialization or ';' in for loop");
        }

        if (peek().type != TOKEN_SEMICOLON)
            addEdge(node, expr());
        if (!match(TOKEN_SEMICOLON, NULL))
            syntaxError("MissingSemicolon", "Expected ';' after for loop condition");

        if (peek().type == TOKEN_IDENTIFIER) {
            addEdge(node, tokenNode(tokens[current++]));
            if (!match(TOKEN_ASSIGN, NULL))
                syntaxError("MissingAssignmentOperator", "Expected '=' in for loop increment");
            addEdge(node, tokenNode(tokens[current - 1]));
            addEdge(node, expr());
        } else if (peek().type != TOKEN_RPAREN) {
            syntaxError("MissingForIncrement", "Expected assignment or ')' in for loop increment");
        }

        if (!match(TOKEN_RPAREN, NULL))
            syntaxError("MissingClosingParenthesis", "Expected ')' after for loop increment");

        addEdge(node, tokenNode(tokens[current - 1]));
        addEdge(node, block());
    } else {
        syntaxError("UnknownStatement", "Unknown statement");
    }

    return node;
}

int block() {
    int node = newNode("block");

    if (!match(TOKEN_LBRACE, NULL))
        syntaxError("MissingOpeningBrace", "Expected '{'");
    addEdge(node, tokenNode(tokens[current - 1]));

    while (peek().type == TOKEN_KEYWORD &&
           (strcmp(peek().value, "int") == 0 || strcmp(peek().value, "float") == 0 ||
            strcmp(peek().value, "char") == 0 || strcmp(peek().value, "double") == 0 || strcmp(peek().value, "void") == 0)) {
        addEdge(node, decl());
    }

    while (peek().type == TOKEN_IDENTIFIER || strcmp(peek().value, "return") == 0 ||
           strcmp(peek().value, "if") == 0 || strcmp(peek().value, "while") == 0 || strcmp(peek().value, "for") == 0) {
        addEdge(node, stmt());
    }

    if (!match(TOKEN_RBRACE, NULL))
        syntaxError("MissingClosingBrace", "Expected '}'");
    addEdge(node, tokenNode(tokens[current - 1]));

    return node;
}

int func_def() {
    int node = newNode("func_def");

    if (!(match(TOKEN_KEYWORD, "int") || match(TOKEN_KEYWORD, "float") ||
          match(TOKEN_KEYWORD, "char") || match(TOKEN_KEYWORD, "double") || match(TOKEN_KEYWORD, "void"))) {
        const char *expectedKeywords[] = {"int", "float", "char", "double", "void"};
        suggestKeyword(peek().value, expectedKeywords, 5, peek().line);
        syntaxError("MissingTypeSpecifier", "Expected type specifier");
    }
    addEdge(node, tokenNode(tokens[current - 1]));

    if (!match(TOKEN_IDENTIFIER, NULL))
        syntaxError("MissingFunctionName", "Expected function name");
    addEdge(node, tokenNode(tokens[current - 1]));

    if (!match(TOKEN_LPAREN, NULL))
        syntaxError("MissingOpeningParenthesis", "Expected '(' after function name");
    addEdge(node, tokenNode(tokens[current - 1]));

    if (peek().type == TOKEN_KEYWORD &&
        (strcmp(peek().value, "int") == 0 || strcmp(peek().value, "float") == 0 ||
         strcmp(peek().value, "char") == 0 || strcmp(peek().value, "double") == 0)) {
        addEdge(node, tokenNode(tokens[current++]));
        if (!match(TOKEN_IDENTIFIER, NULL))
            syntaxError("MissingParameterName", "Expected parameter name");
        addEdge(node, tokenNode(tokens[current - 1]));
    }

    if (!match(TOKEN_RPAREN, NULL))
        syntaxError("MissingClosingParenthesis", "Expected ')' after parameters");
    addEdge(node, tokenNode(tokens[current - 1]));

    addEdge(node, block());

    return node;
}

int func_def_list() {
    int node = newNode("func_def_list");
    while (peek().type == TOKEN_KEYWORD &&
           (strcmp(peek().value, "int") == 0 || strcmp(peek().value, "float") == 0 ||
            strcmp(peek().value, "char") == 0 || strcmp(peek().value, "double") == 0 || strcmp(peek().value, "void") == 0)) {
        addEdge(node, func_def());
    }
    return node;
}

int program() {
    int node = newNode("program");
    addEdge(node, func_def_list());
    return node;
}

void parseTokens(Token inputTokens[], int count) {
    memcpy(tokens, inputTokens, sizeof(Token) * count);
    current = 0;
    nodeId = 0;

    dotFile = fopen("tree.dot", "w");
    fprintf(dotFile, "digraph ParseTree {\n");
    fprintf(dotFile, "  node [shape=box, fontname=\"Courier\"];\n");

    int root = program();

    fprintf(dotFile, "}\n");
    fclose(dotFile);

    printf("Parse tree generated: tree.dot\n");
}
