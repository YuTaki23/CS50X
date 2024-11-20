#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_alpha(string argv);
bool characters_equals_26(string argv);
string plain_to_cipher(string k, string text);
bool contain_same_key(string argv);

int main(int argc, char *argv[]) {
    // 只有一个命令行参数，加上程序名，argc = 2
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    } else if (!(only_alpha(argv[1]))) {
        printf("Usage: ./substitution key\n");
        return 1;
    } else if (!(characters_equals_26(argv[1]))) {
        printf("key must contain 26 characters\n");
        return 1;
    } else if (!(contain_same_key(argv[1]))) {
        printf("key can not contain same key.\n");
        return 1;
    }
    // printf("ok\n");
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: %s\n", plain_to_cipher(argv[1], plaintext));
    return 0;
}

bool only_alpha(string argv) {
    bool result = true;
    for (int i = 0; i < strlen(argv); i++) {
        if (!isalpha(argv[i])) {
            result = false;
        }
    }
    return result;
}

bool characters_equals_26(string argv) {
    bool result = true;
    if (strlen(argv) != 26) {
        result = false;
    }
    return result;
}

bool contain_same_key(string argv) {
    bool result = true;
    for (int i = 0; i < strlen(argv); i++) {
        for (int j = i + 1; j < strlen(argv); j++) {
            if (argv[i] == argv[j]) {
                return false;
            }
        }
    }
    return true;
}

string plain_to_cipher(string k, string text) {
    char key[26];
    string cipher;
    for (int i = 0; i < strlen(k); i++) {
        key[i] = toupper(k[i]);
    }

    for (int i = 0; i < strlen(text); i++) {
        if (isupper(text[i])) {
            text[i] = toupper(key[(text[i] - 'A')]);
        } else if (islower(text[i])) {
            text[i] = tolower(key[(text[i] - 'a')]);
        } else {
            text[i] = text[i];
        }
    }
    return text;
}
