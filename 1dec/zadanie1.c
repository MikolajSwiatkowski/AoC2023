#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

size_t line_length;

char line_x[64];

unsigned long int sum = 0;
unsigned int line_value = 0;
char first_in_line;
char last_in_line;
char *ptr;

char *words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *numbers[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

void main()
{
    //fileopen
    FILE* fptr = fopen("input1.txt", "r");

    if (fptr == NULL)
    {
        printf("Failed to open input1.txt \n");
        exit(0);
    }
    else 
    {
        printf("input1.txt loaded \n");
    }

    while(1)
    {
        fgets(line_x, sizeof line_x, fptr);
        line_length = strlen(line_x);

        for (int c = 0; c < line_length-1; c++ ){
            for(int i = 0; i < 9; i++)
            {
                ptr = strstr(line_x + c, words[i]);
                if (ptr == line_x + c) {
                char word_pos = ptr - line_x;
                line_x[word_pos] = *numbers[i];
                }
            }
        }
 
        int j = 0;
        while (1)
        {
            if (isdigit(line_x[j]) != 0)
            {
                first_in_line = line_x[j];
                break;
            }
            else
            {
                j++;
            }
        }

        int k = line_length - 1;
        while (1)
        {
            if (isdigit(line_x[k]) != 0)
            {
                last_in_line = line_x[k];
                break;
            }
            else
            {
                k--;
            }
        }
        line_value = ((first_in_line - '0') * 10) + (last_in_line - '0');
        sum += line_value;
        if(feof(fptr)){break;}
    }
    printf("SUM: %u\n", sum);
}