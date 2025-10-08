//This program prints its input one "word" per line. Yes, avoids consecutive newlines.

#include <stdio.h>
#define INLEN 33
#define SPACE 32
#define PADDING 2
#define TAB 9
#define NEWLINE 10

int main(void)
{
    char input[INLEN] = "Text with\twords    and stuff.\t .";
    char output[INLEN*PADDING] = "";

    int C =0;
    char last =0;

    for (int i=0; i<INLEN; i++)
    {
        if(input[i] == SPACE || input[i] == TAB)
        {
            if (last !=NEWLINE)
            {
                output[i-C] = NEWLINE;
            }
            else
            {
                C++; //Hehe
            }
        }
        else
        {
            output[i-C] = input[i];
        }

        last = output[i-C];
    }
    printf("\n%s\n\nRemoved %d\n", output, C);
    return 0;
}