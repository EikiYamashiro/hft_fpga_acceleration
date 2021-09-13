// gcc -Wall -pedantic -std=gnu99 -Og -o reader_line reader_line.c

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("gen_prices.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
        printf("%f \n", atof(line));
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}