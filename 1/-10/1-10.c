//This replaces '\b', '\t' and '\\' characters with their visual equivalents

#include <stdio.h>

#define TAB 9
#define NEWLINE 10
#define BACKSPACE 8
#define BACKSLASH 92
#define SPACE 32
#define INLEN 63
#define PADDING 2

int main(void)
{

char input[INLEN] = "This is some text with \bBackspaces, \t\t tabs and \\ backslashes.";
char output[INLEN*PADDING] = "";

int added_letters = 0;

for (int i = 0; i < INLEN*PADDING; i++)
{

    if(input[i] == TAB)
    {
        output[i+added_letters]='\\';
        added_letters++;
        output[i+added_letters]='t';
    }

    else if(input[i] == BACKSPACE)
    {
        output[i+added_letters]='\\';
        added_letters++;
        output[i+added_letters]='b';
    }
    else if(input[i] == BACKSLASH)
    {
        output[i+added_letters]='\\';
        added_letters++;
        output[i+added_letters]='\\';
    }
    else
    {
        output[i+added_letters] = input[i];
    }
}

//This is technically optional, but it cleans up garbage characters after the end of the original string.
//I guess it also works as a failsafe against missing null terminators?
for (int i = INLEN*PADDING; i>INLEN+added_letters; i--)
{
    output[i] = '\000';
}

printf("\n%s\nAdded %d Characters\n",output,added_letters);
return 0;

}
