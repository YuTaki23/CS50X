#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main() {
    int letter, word, sentence;
    int index;
    float L, S;
    string text = get_string("Text: ");

    letter = count_letters(text);
    word = count_words(text);
    sentence = count_sentences(text);

    L = ((float)letter / (float)word) * 100;
    S = ((float)sentence / (float)word) * 100;
    index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >= 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", index);
    }

    return 0;
}

int count_letters(string text) {
    int count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            count++;
        }
    }
    return count;
}

int count_words(string text) {
    int count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            count++;
       }
    }
    return count;
}

int count_sentences(string text) {
    int count = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (ispunct(text[i])) {
            if ((text[i] == '.') || (text[i] == '?') || (text[i] == '!')) {
                count++;
            }
        }
    }
    return count;
}
