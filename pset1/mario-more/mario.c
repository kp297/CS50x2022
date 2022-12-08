#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n = 0;

    //loop - do while to get value
    do
    {
        n = get_int("Please pick a value between 1 and 8: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < (n - i); j++)  //loop to add whitespace
        {
            printf(" ");
        }

        for (int k = 0; k < (i + 1); k++) //loop for left #
        {
            printf("#");
        }

        printf("  "); //printing space in the middle

        for (int l = 0; l < (i + 1); l++) //loop for right #
        {
            printf("#");
        }
        printf("\n");
    }

}