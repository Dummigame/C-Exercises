//This looks a lot tougher than the last exercise...
//This program draws a histogram of the frequency of words in its input.

#include <stdio.h> //I keep forgetting this

#define TAB 9
#define NEWLINE 10
#define BACKSPACE 8
#define BACKSLASH 92
#define SPACE 32
#define INLEN 37
#define PADDING 2
#define TRUE 1
#define FALSE 0
#define BORDER_PADDING -11

int main(void)
{
    char input[INLEN] = "this is some text. is this working?";
    char process[INLEN+1] = "";


    int C =0;
    char last =0;
    int longest =0;
    int current_len =0;
    int word_count =0;
    int words_len[INLEN/PADDING+1];

    for (int i=0; input[i]; i++)
    {
        if(input[i] == SPACE || input[i] == TAB) //Convert input so a '\n' is inserted after every word and other blanks are removed
        {
            if (last !=NEWLINE)
            {
                process[i-C] = NEWLINE;
            }
            else
            {
                C++; //Hehe
            }
        }
        else
        {
            process[i-C] = input[i];
        }

        last = process[i-C];
    }

    for (int i=0; process[i]; i++) //Get the length of each word
    {
        if(process[i] == NEWLINE)
        {
            words_len[word_count] = current_len;
            current_len = 0;
            word_count++;
        }
        else if (process[i])
            {
                current_len++;
                if(current_len > longest)
                {
                    longest++;
                }
            }
    }
    words_len[word_count] = current_len;

    printf("\n");

    for(int i =0; i+BORDER_PADDING<=longest; i++) //Print upper border
    {
        printf("=");
    }
    printf("\n");

    for(int i = 0; i<=word_count; i++) //Print the histogram
    {
        printf("Word %d: |", i+1);

        for(int i_ = 0; i_<=words_len[i]; i_++)
        {
            if(i_ +1 < words_len[i])
            {
                printf("-");
            }

            if(i_ +1 == words_len[i])
            {
                printf("-|");
            }


            if(i_ == words_len[i])
            {
                printf("\n");
            }
        }
    }

    for(int i =0; i+BORDER_PADDING<=longest; i++) //Print lower border
    {
        printf("=");
    }
    printf("\n");
    
    return 0;
}




// int compare_strings(&char[]a, &char[]b)
// {
//     int i=0
//     while (a || b)
//     {
//         if(a[i] == b[i])
//         {
//             i++;
//         }
//         else
//         {
//             return FALSE;
//         }
//     }
//     return TRUE;
// }