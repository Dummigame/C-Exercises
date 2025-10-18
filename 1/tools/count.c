#include <stdio.h>
int main()
{
    char input[1000000]= "This is the longest line by  a little, so it should appear as the output...... hopefully.";
    for (int i=0; input[i]!=0; i++)
    {
        if (input[i])
        {
            printf("%d\n", i+1);
        }
    }
        
}