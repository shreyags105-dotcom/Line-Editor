#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editor.h"

char *lines[MAX_LINES];
int line_count = 0;

void insert_line(int n, char *text) {
    if (n < 1 || n > line_count + 1) {
        printf("Error: invalid line number %d\n", n);
        return;
    }
    if (line_count >= MAX_LINES) {
        printf("Error: document full\n");
        return;
    }
    for (int i = line_count; i >= n; i--) {
        lines[i] = lines[i - 1];
    }
    lines[n - 1] = malloc(strlen(text) + 1);
    strcpy(lines[n - 1], text);
    line_count++;
}

void delete_line(int n) {
    if (line_count == 0) {
        printf("Error: document is empty\n");
        return;
    }
    if (n < 1 || n > line_count) {
        printf("Error: invalid line number %d\n", n);
        return;
    }
    free(lines[n - 1]);
    for (int i = n - 1; i < line_count - 1; i++) {
        lines[i] = lines[i + 1];
    }
    line_count--;
}

void display(void) {
    if (line_count == 0) {
        printf("(empty document)\n");
        return;
    }
    for (int i = 0; i < line_count; i++) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}