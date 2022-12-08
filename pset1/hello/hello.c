#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Please tell me your name: "); //get input from the user
    printf("hello, %s\n", name);
}