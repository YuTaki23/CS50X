#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digit(string argv);
char rotate(char c, int n);

int main(int argc, char *argv[]) {
    // 只有一个命令行参数，加上程序名，argc = 2
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // 命令行参数必须为数字
    else if (!only_digit(argv[1])) {
        printf("Usage: ./caesqr key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    string str = get_string("Plain text: ");

    for(int i = 0; i < strlen(str); i++) {
        str[i] = rotate(str[i], key);
    }
    printf("Ciphertext: %s\n", str);
    return 0;

}

bool only_digit(string argv) {
    bool result = false;
    for (int i = 0; i < strlen(argv); i++) {
        if (isdigit(argv[i])) {
            result = true;
        } else {
            result = false;
        }
    }
    return result;
}

char rotate(char c, int n) {
    if (isupper(c)) {
        return ((c - 65) + n) % 26 + 65;
    } else if (islower(c)) {
        return (c - 97 + n) % 26 + 97;
    } else {
        return c;
    }
}
