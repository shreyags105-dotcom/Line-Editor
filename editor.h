#ifndef EDITOR_H
#define EDITOR_H

#define MAX_LINE_LEN 256
#define MAX_LINES 1000

extern char *lines[MAX_LINES];
extern int line_count;

void insert_line(int n, char *text);
void delete_line(int n);
void display(void);
void save_file(char *filename);
void load_file(char *filename);

#endif