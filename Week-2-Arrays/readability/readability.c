#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters_count = count_letters(text);
    // printf("%d\n", letters_count);

    int words_count = count_words(text);
    // printf("%d\n", words_count);

    int sentences_count = count_sentences(text);
    // printf("%d\n", sentences_count);

    int index = (int) round(0.0588 * ((float) letters_count / words_count) * 100 -
                            0.296 * ((float) sentences_count / words_count) * 100 - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]) || islower(text[i]) || isdigit(text[i]))
        {
            count++;
        }
    }

    return count;
}

int count_words(string text)
{
    int count = 0;
    bool is_word = false;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((islower(text[i]) || isupper(text[i]) || isdigit(text[i])) && !is_word)
        {
            count++;
            is_word = true;
        }
        else if ((text[i] == ' ' || (text[i] != '\'' && text[i] != '-' && ispunct(text[i]))) && is_word)
        {
            is_word = false;
        }
    }

    return count;
}

int count_sentences(string text)
{
    int count = 0;

    bool is_sentence = false;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((islower(text[i]) || isupper(text[i]) || isdigit(text[i])) && !is_sentence)
        {
            count++;
            is_sentence = true;
        }
        else if ((text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == '\0') && is_sentence)
        {
            is_sentence = false;
        }
    }

    return count;
}
