#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

const int N = 26;
int POINTS[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_letter(string str);

int main() {
    int result1, result2;

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    result1 = calculate_letter(word1);
    result2 = calculate_letter(word2);

    if (result1 > result2) {
        printf("Player 1 wins!\n");
    } else if (result1 < result2) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}

int calculate_letter(string str) {
    int sum = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (isupper(str[i])) {
            sum += POINTS[str[i] - 'A'];
        }
        if (islower(str[i])) {
            sum += POINTS[str[i] - 'a'];
        }
    }
    return sum;
}
