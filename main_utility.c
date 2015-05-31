#include "main_utility.h"

#include <stdio.h> /* for fgetc(3), stdin, and EOF */
#include <stdlib.h> /* for malloc(3), realloc(3), and free(3) */

char *get_line() {
    char *line = malloc(300);
    int i = 0;
    while(i == 0 || line[i-1] != '\n'){
        if(i > 298){
            printf("{ error: \"Input truncated, reached maximum length.\" }\n");
            break;
        }
        line[i] = getchar();
        i++;
    }
    return line;
}
