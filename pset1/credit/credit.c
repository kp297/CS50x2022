#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num = get_long("Please input credit card number: ");
    int counter = 1;
    int evensum = 0;
    int oddsum = 0;
    int checksum = 0;
    int dc = 0;
    int digit = 0;
    int checkbrand = 0;

    while (num > 0)
    {
        digit = num % 10;
        if (counter % 2 == 0) // picking all even digits
        {
            dc = digit * 2;
            if (dc > 9)
            {
                evensum = evensum + (dc % 10) + (dc / 10); // adding digits when they are double digit
            }
            else
            {
                evensum = evensum + dc; // adding digits when they are single digit
            }


        }
        else // picking all odd digits
        {
            oddsum = oddsum + digit;
        }
        num = num / 10;
        counter++;
        if (num > 9 && num < 100)
        {
            checkbrand = num;
        }
    }
    checksum = (evensum + oddsum) % 10;



    if (checksum == 0)
    {
        if (checkbrand == 37 || checkbrand == 34) //check for AMEX
        {
            printf("AMEX\n");
        }
        else if (checkbrand > 50 && checkbrand < 56) //check for Mastercard
        {
            printf("MASTERCARD\n");
        }
        else if (checkbrand / 10 == 4 && (counter == 17 || counter == 14)) //check for Visa
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}