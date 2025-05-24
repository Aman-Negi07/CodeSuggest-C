#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "semantic.h"
#include "ir.h"
#include "tcg.h" 
#define MAX_CODE_SIZE 10000

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (!file)
    {
        perror("input.txt");
        return 1;
    }

    char code[MAX_CODE_SIZE];
    size_t bytesRead = fread(code, 1, MAX_CODE_SIZE - 1, file);
    code[bytesRead] = '\0'; // Null-terminate the buffer
    fclose(file);

    tokenize(code);
    writeTokensToFile("tokens.txt");

    parseTokens(tokens, tokenCount);
    checkSemantics(tokens, tokenCount);

    generateIR(tokens, tokenCount);
    generateTargetCode("ir.txt", "targetCode.txt"); // Call to the new target code generation function
    printf("Target Code generation completed successfully.\n");
    return 0;
}