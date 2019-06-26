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
            
            case '[':
                if(memory[ptr] == 0)
                {
                    int l = 0;  // Number of nested if statements
                    int no_close = 1;
                    while(no_close)
                    {
                        i++;
                        // Error if no ending bracket is found
                        if(i == MAX_LINE)
                        {
                            printf("Error, no end bracket found for if statement");
                            exit(1);
                        }

                        switch(line[i])
                        {
                            case '[':
                                l++;
                                break;

                            case ']':
                                if(l == 0)
                                    no_close = 0;
                                else
                                    l--;
                                break;
                        }
                    }
                }
                break;

            case ']':
                if(memory[ptr] != 0)
                {
                    int l = 0;  // Number of nested if statements
                    int no_close = 1;
                    while(no_close)
                    {
                        i--;
                        // Error if no ending bracket is found
                        if(i == -1)
                        {
                            printf("Error, no start bracket found for if statement");
                            exit(1);
                        }

                        switch(line[i])
                        {
                            case ']':
                                l++;
                                break;

                            case '[':
                                if(l == 0)
                                    no_close = 0;
                                else
                                    l--;
                                break;
                        }
                    }
                }
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
