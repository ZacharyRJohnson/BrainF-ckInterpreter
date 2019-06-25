#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 256
#define VIRTUAL_MEM_SIZE 1024

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

void execute(char* line)
{
    int ptr = 0;
    int memory[VIRTUAL_MEM_SIZE] = {0};

    for(int i=0; i < VIRTUAL_MEM_SIZE; i++){
        char symbol = line[i];
        switch(symbol)
        {
            case '<':
                if(ptr == 0)
                    ptr = VIRTUAL_MEM_SIZE - 1;
                else
                    ptr--;
                break;

            case '>':
                if(ptr == VIRTUAL_MEM_SIZE-1)
                    ptr = 0;
                else
                    ptr++;
                break;

            case '+':
                memory[ptr]++;
                break;

            case '-':
                memory[ptr]--;
                break;

            case '.':
                printf("%d\n", memory[ptr]);
                break;

            case ',':
                fgets((int*)memory[ptr], 1, stdin);
                break;

        }
    }
}

int main()
{
    char *line;
    line = read_line();
    execute(line);
    free(line);
    return(0);
}
