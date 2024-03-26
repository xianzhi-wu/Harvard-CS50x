#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

void print_row(int spaces, int bricks);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        int s = n - i - 1;
        int b = i + 1;
        print_row(s, b);
    }
}

void print_row(int spaces, int bricks)
{
    //char row[spaces + bricks];
    char *row = malloc((spaces + bricks) * sizeof(char));

    int i = 0;

    while (spaces > 0)
    {
        row[i] = ' ';
        i++;
        spaces--;
    }

    while (bricks > 0)
    {
        row[i] = '#';
        i++;
        bricks--;
    }

    printf("%s\n", row);
}
