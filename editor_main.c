#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

void save_file(char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        printf("Error: could not open %s for writing\n", filename);
        return;
    }
    for (int i = 0; i < line_count; i++) {
        fprintf(f, "%s\n", lines[i]);
    }
    fclose(f);
    printf("Saved to %s\n", filename);
}

void load_file(char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Error: could not open %s for reading\n", filename);
        return;
    }
    char buffer[MAX_LINE_LEN];
    line_count = 0;
    while (fgets(buffer, MAX_LINE_LEN, f) != NULL && line_count < MAX_LINES) {
        buffer[strcspn(buffer, "\n")] = '\0';
        lines[line_count] = malloc(strlen(buffer) + 1);
        strcpy(lines[line_count], buffer);
        line_count++;
    }
    fclose(f);
    printf("Loaded from %s (%d lines)\n", filename, line_count);
}

int main(void) {
    char input[MAX_LINE_LEN];
    printf("Simple Line Editor. Commands: i <n> <text> | d <n> | p | w <file> | r <file> | q\n");

    while (1) {
        printf("> ");
        if (fgets(input, MAX_LINE_LEN, stdin) == NULL) break;
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) == 0) continue;

        char cmd = input[0];

        if (cmd == 'q') {
            break;
        } else if (cmd == 'p') {
            display();
        } else if (cmd == 'i') {
            int n;
            char text[MAX_LINE_LEN];
            if (sscanf(input + 1, "%d %[^\n]", &n, text) == 2) {
                insert_line(n, text);
            } else {
                printf("Usage: i <line#> <text>\n");
            }
        } else if (cmd == 'd') {
            int n;
            if (sscanf(input + 1, "%d", &n) == 1) {
                delete_line(n);
            } else {
                printf("Usage: d <line#>\n");
            }
        } else if (cmd == 'w') {
            char filename[MAX_LINE_LEN];
            if (sscanf(input + 1, "%s", filename) == 1) {
                save_file(filename);
            } else {
                printf("Usage: w <filename>\n");
            }
        } else if (cmd == 'r') {
            char filename[MAX_LINE_LEN];
            if (sscanf(input + 1, "%s", filename) == 1) {
                load_file(filename);
            } else {
                printf("Usage: r <filename>\n");
            }
        } else {
            printf("Unknown command: %c\n", cmd);
        }
    }

    for (int i = 0; i < line_count; i++) free(lines[i]);
    return 0;
}