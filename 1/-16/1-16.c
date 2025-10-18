#include <stdio.h>
#define MAXLEN 1000

int get_longest_len(char input[], int total_len);
int get_input_length(char input[]);
int get_offset_from_longest(char input[], int longest_len, int total_len);
void print_longest_line(char input[], int longest_len, int offset, int total_len);

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    char input[MAXLEN]="This is a whole lotta text. It has many\tdifferent\n\n\nkinds of symbols. \nThis is the longest line by  a little, so it should appear as the output...... hopefully.\n blah blah extra text";
    int total_len = get_input_length(input);
    int longest_len = get_longest_len(input, total_len);
    int offset = get_offset_from_longest(input, longest_len, total_len);

    printf("\nTotal Length: %d", total_len);
    printf("\nLength of longest line: %d", longest_len);
    printf("\nOffset from start of string: %d\n", offset);

    print_longest_line(input, longest_len, offset, total_len);

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

int get_input_length(char input[])
{
    int length=0;
    for (int i=0; input[i]; i++)
    {
        if (i>=MAXLEN)
        {
            length=0;
            break; //Prevents infinite loop
        }

        if(input[i])
        {
            length++;
        }
    }

    return length;
}

//////////////////////////////////////////////////////////////////////////

int get_longest_len(char input[], int total_len)
{
    int current_len=0;
    int longest_len=0;
    int newlines=0;

    for(int i=0; i<total_len; i++)
    {
       if(input[i] != '\n')
       {
            current_len++;
       }
       else
       {
            newlines++;
            current_len=0;
       }
        if(current_len > longest_len)
        {
            longest_len = current_len;
        }
    }

    return longest_len;
}

////////////////////////////////////////////////////////////////////

int get_offset_from_longest(char input[], int longest_len, int total_len)
{
    int offset =0;
    int since_last_newline=0;

    for(int i=1; i<=total_len; i++)
    {
        if(input[i] != '\n')
        {
            since_last_newline++;
        }
        else
        {
            since_last_newline=0;
        }
        if (since_last_newline == longest_len)
        {
            offset = i-longest_len;
        }
    }

    return offset;
}

/////////////////////////////////////////////////////////////////////

void print_longest_line(char input[], int longest_len, int offset, int total_len)
{
    char longest_line[longest_len+1]; //+1 to allow for added null terminator

    for(int i=offset; i<=offset+longest_len; i++)
    {
        longest_line[i-offset]=input[i];
    }

    longest_line[longest_len+1] = 0; //Ensures null terminator is at end of string.

    printf("\nLongest line: %s\n", longest_line);
    return;
}