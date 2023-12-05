#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void get_line();
int check_line();

char line_x[128];

FILE* fptr;

int main()
{
    //fileopen

    fptr = fopen("input1.txt", "r");

    if (fptr == NULL)
    {
        printf("Failed to open input1.txt \n");
        exit(0);
    }
    else 
    {
        printf("input1.txt loaded \n");
    }

    while (feof(fptr) != EOF)
    {
        get_line();
        //check_line();
    }

    return 0;
}


void get_line()
{
    memset(line_x, 0, sizeof(line_x));
    fgets(line_x, sizeof line_x, fptr);
    printf(line_x);
}

int check_line()
{
    for(int i = 0; i < sizeof(line_x); i++)
    {
        if (isdigit(line_x[i]))
        {
            
        }
    }
}