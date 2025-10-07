//This program removes consecutive blanks and newlines

#include <stdio.h>

#define TAB 9
#define NEWLINE 10
#define SPACE 32
#define INLEN 62

int main(void)
{

char input[INLEN] = "This is some text with   Spaces, \t\t tabs and \n\n\nnewlines.";
char output[INLEN] = "";

int reader = 0;
int last = 0;
int removed_letters = 0;

for (int i = 0; i < INLEN; i++)
{
    reader = input[i];
    if (reader == NEWLINE)
    {
        if(last == NEWLINE)
            {
                last = input[i];
                removed_letters++;
                continue;
            }
        last = NEWLINE;
        output[i-removed_letters] = input[i];
    }
    else if (reader == TAB)
    {
        if(last == TAB)
        {
            last = input[i];
            removed_letters++;
            continue;
        }
        last = TAB;
        output[i-removed_letters] = input[i];
    }
    else if (reader == SPACE)
    {
        if(last == SPACE)
        {
            last = input[i];
            removed_letters++;
            continue;
        }
        last = SPACE;
        output[i-removed_letters] = input[i];

    }
    else 
    {
        last = 0;
        output[i-removed_letters] = input[i];
    }
}

printf("\n%s\nRemoved %d \n",output,removed_letters);
return 0;

}
