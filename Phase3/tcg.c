#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trim(char *str) {
    while (*str == ' ' || *str == '\t') str++;  // Skip leading spaces

    char *end = str + strlen(str) - 1;
    while (end > str && (*end == '\n' || *end == '\r' || *end == ' ' || *end == '\t'))
        *end-- = 0;  // Trim trailing whitespace/newlines

    return str;
}

void generateTargetCode(const char *irFile, const char *targetFile) {
    FILE *ir = fopen(irFile, "r");
    if (!ir) {
        perror(" Failed to open IR file");
        return;
    }

    FILE *target = fopen(targetFile, "w");
    if (!target) {
        perror(" Failed to open Target file");
        fclose(ir);
        return;
    }

    char raw[256];
    while (fgets(raw, sizeof(raw), ir)) {
        char *line = trim(raw);

        if (line[0] == '\0' || line[0] == '#') continue;

        char lhs[32], op1[32], op2[32], label[32];

        // Relational operations
        if (strstr(line, "==")) {
            if (sscanf(line, "%s = %s == %s", lhs, op1, op2) == 3) {
                fprintf(target,
                    "LOAD %s\nSUB %s\nJZ SET1_%s\nLOAD 0\nSTORE %s\nJMP ENDSET_%s\n"
                    "SET1_%s:\nLOAD 1\nSTORE %s\nENDSET_%s:\n",
                    op1, op2, lhs, lhs, lhs, lhs, lhs, lhs);
            }
            continue;
        }

        if (strstr(line, "!=")) {
            if (sscanf(line, "%s = %s != %s", lhs, op1, op2) == 3) {
                fprintf(target,
                    "LOAD %s\nSUB %s\nJNZ SET1_%s\nLOAD 0\nSTORE %s\nJMP ENDSET_%s\n"
                    "SET1_%s:\nLOAD 1\nSTORE %s\nENDSET_%s:\n",
                    op1, op2, lhs, lhs, lhs, lhs, lhs, lhs);
            }
            continue;
        }

        if (strstr(line, ">=")) {
            if (sscanf(line, "%s = %s >= %s", lhs, op1, op2) == 3) {
                fprintf(target,
                    "LOAD %s\nSUB %s\nJGEZ SET1_%s\nLOAD 0\nSTORE %s\nJMP ENDSET_%s\n"
                    "SET1_%s:\nLOAD 1\nSTORE %s\nENDSET_%s:\n",
                    op1, op2, lhs, lhs, lhs, lhs, lhs, lhs);
            }
            continue;
        }

        if (strstr(line, "<=")) {
            if (sscanf(line, "%s = %s <= %s", lhs, op1, op2) == 3) {
                fprintf(target,
                    "LOAD %s\nSUB %s\nJLEZ SET1_%s\nLOAD 0\nSTORE %s\nJMP ENDSET_%s\n"
                    "SET1_%s:\nLOAD 1\nSTORE %s\nENDSET_%s:\n",
                    op1, op2, lhs, lhs, lhs, lhs, lhs, lhs);
            }
            continue;
        }

        if (strstr(line, ">")) {
            if (sscanf(line, "%s = %s > %s", lhs, op1, op2) == 3) {
                fprintf(target,
                    "LOAD %s\nSUB %s\nJGTZ SET1_%s\nLOAD 0\nSTORE %s\nJMP ENDSET_%s\n"
                    "SET1_%s:\nLOAD 1\nSTORE %s\nENDSET_%s:\n",
                    op1, op2, lhs, lhs, lhs, lhs, lhs, lhs);
            }
            continue;
        }

        if (strstr(line, "<")) {
            if (sscanf(line, "%s = %s < %s", lhs, op1, op2) == 3) {
                fprintf(target,
                    "LOAD %s\nSUB %s\nJLTZ SET1_%s\nLOAD 0\nSTORE %s\nJMP ENDSET_%s\n"
                    "SET1_%s:\nLOAD 1\nSTORE %s\nENDSET_%s:\n",
                    op1, op2, lhs, lhs, lhs, lhs, lhs, lhs);
            }
            continue;
        }

        // Arithmetic operations
        if (strstr(line, "=") && strstr(line, "+")) {
            if (sscanf(line, "%s = %s + %s", lhs, op1, op2) == 3) {
                fprintf(target, "LOAD %s\nADD %s\nSTORE %s\n", op1, op2, lhs);
            }
        } else if (strstr(line, "=") && strstr(line, "-")) {
            if (sscanf(line, "%s = %s - %s", lhs, op1, op2) == 3) {
                fprintf(target, "LOAD %s\nSUB %s\nSTORE %s\n", op1, op2, lhs);
            }
        } else if (strstr(line, "=") && strstr(line, "*")) {
            if (sscanf(line, "%s = %s * %s", lhs, op1, op2) == 3) {
                fprintf(target, "LOAD %s\nMUL %s\nSTORE %s\n", op1, op2, lhs);
            }
        } else if (strstr(line, "=") && strstr(line, "/")) {
            if (sscanf(line, "%s = %s / %s", lhs, op1, op2) == 3) {
                fprintf(target, "LOAD %s\nDIV %s\nSTORE %s\n", op1, op2, lhs);
            }
        } else if (strstr(line, "=")) {
            if (sscanf(line, "%s = %s", lhs, op1) == 2) {
                fprintf(target, "LOAD %s\nSTORE %s\n", op1, lhs);
            }
        }

        // Control flow
        else if (strncmp(line, "if", 2) == 0) {
            if (sscanf(line, "if %s goto %s", op1, label) == 2) {
                fprintf(target, "LOAD %s\nJNZ %s\n", op1, label);
            }
        } else if (strncmp(line, "goto", 4) == 0) {
            if (sscanf(line, "goto %s", label) == 1) {
                fprintf(target, "JMP %s\n", label);
            }
        } else if (strncmp(line, "return", 6) == 0) {
            if (sscanf(line, "return %s", op1) == 1) {
                fprintf(target, "LOAD %s\nOUT\n", op1);
            }
        } else if (line[0] == 'L') {
            fprintf(target, "%s:\n", line);  // Write label line (with colon)
        } else {
            fprintf(stderr, "Skipped unrecognized line: %s\n", line);
        }
    }

    fclose(ir);
    fclose(target);
    printf(" Target code generated at: %s\n", targetFile);
}
