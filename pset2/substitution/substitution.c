#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2) //check if correct arguments present
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string cipher = argv[1];
    int cl = strlen(cipher);

    for (int k = 0; k < cl; k++) //check if key is only alphabets
    {
        if (!isalpha(cipher[k]))
        {
            printf("Key must be alphabetical.\n");
            return 1;
        }

    }

    if (strlen(cipher) != 26) //check if key is only 26 characters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //check for duplicates

    for (int i = 0; i < (cl - 1); i++)
    {
        for (int j = i + 1; j < cl; j++)
        {
            if (cipher[i] == cipher[j])
            {
                printf("Key must not have duplicates.\n");
                return 1;
            }

        }
    }


    string val = get_string("plaintext: ");

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    int l = strlen(val);



    for (int i = 0; i < l; i++) //loop across input word
    {
        if (islower(val[i])) //for lowercase
        {
            for (int j = 0; j < 26; j++) //loop across alphabet and cipher
            {
                if (val[i] == alphabet[j])
                {
                    val[i] = tolower(cipher[j]);
                    break;

                }

            }

        }
        else if (isupper(val[i])) //for upper case
        {
            for (int j = 0; j < 26; j++)
            {
                if (val[i] == toupper(alphabet[j]))
                {
                    val[i] = toupper(cipher[j]);
                    break;
                }


            }

        }

    }
    printf("ciphertext: %s\n", val);

    return 0;


}