#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 256
/*
 * Reads a single line of code from stdin
 */
char* read_line()
{
    char *line;
    line = calloc(1, sizeof(char)*MAX_LINE);

    printf("$ ");
    fgets(line, MAX_LINE, stdin);
    return line;
}

int main()
{
    char *line;
    line = read_line();
    printf("%s", line);

    free(line);
    return(0);
}
