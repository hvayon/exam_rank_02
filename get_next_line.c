#include "get_next_line.h"

int get_next_line(char **line)
{
    int rd = 0; 
    int i = 0;
    char *buffer = malloc(100000);
    *line = buffer;
    while ((rd = read(0, &buffer[i], 1)) > 0 && buffer[i] != '\n')
        i++;
    buffer[i] = '\0';
    return(rd);
}


// for test

/*
#include <stdio.h>

int main(void)
{
    char *line;
    get_next_line(&line);
    printf("%s", line);
}
*/