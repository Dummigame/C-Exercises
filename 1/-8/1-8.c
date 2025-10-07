//This program counts \n, \t and ' '

#include <stdio.h>

#define TAB 9
#define NEWLINE 10
#define SPACE 32
#define INLEN 58
/* count characters in input; 2nd version */
int main(void)
{

char input[INLEN] = "This is some text with Spaces, \t\t tabs and \n\n\n newlines.";
int reader = 0;

int tab = 0;
int newline = 0;
int space = 0;

for (int i = 0; i < INLEN; i++)
{
    reader = input[i];
    if (reader == NEWLINE)
    {
        newline++;
    }
    else if (reader == TAB)
    {
        tab++;
    }
    else if (reader == SPACE)
    {
        space++;
    }
}

printf("\nTabs: %d \nNewlines: %d \nSpaces: %d \n", tab, newline, space);
return 0;

}