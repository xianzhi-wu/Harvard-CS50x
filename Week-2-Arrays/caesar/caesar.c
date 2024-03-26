#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char cipher = rotate(plaintext[i], key);
        printf("%c", cipher);
    }

    printf("\n");
}

bool only_digits(string key)
{
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }

    return true;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        char cipher = (char) (((int) c - 'A' + n) % 26 + 'A');
        return cipher;
    }
    else if (islower(c))
    {
        char cipher = (char) (((int) c - 'a' + n) % 26 + 'a');
        return cipher;
    }

    return c;
}
