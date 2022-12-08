#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string str = get_string("Text: ");
    int l = strlen(str);
    int letter = 0;
    int word = 1;
    int sentence = 0;
    int index = 0;


    for (int i = 0; i < l; i++)
    {
        if (isalpha(str[i])) //check if there is a letter in the sentence
        {
            letter++;
        }

        if (str[i] == 32) //check spaces to count the words
        {
            word++;
        }

        if (str[i] == 33 || str[i] == 46 || str[i] == 63) //check if there are . or ? or ! to count sentences
        {
            sentence++;
        }
    }

    index = round(0.0588 * (letter * 100.0 / word) - 0.296 * (sentence * 100.0 / word) - 15.8); //calculation for grade level

    if (index < 2)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }



}
