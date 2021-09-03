// gcc -Wall -pedantic -std=gnu99 -Og -o reader reader.c

// C program to illustrate fopen()
 
#include <stdio.h>
 
int main()
{
 
    // pointer demo to FILE
    FILE* demo;
    int display;
 
    // Creates a file "demo_file"
    // with file acccess as read mode
    demo = fopen("gen_prices.txt", "r");
 
    // loop to extract every characters
    while (1) {
        // reading file
        display = fgetc(demo);
 
        // end of file indicator
        if (feof(demo))
            break;
 
        // displaying every characters
        printf("%c", display);
    }
 
    // closes the file pointed by demo
    fclose(demo);
 
    return 0;
}