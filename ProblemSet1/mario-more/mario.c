#include <stdio.h>
#include <cs50.h>

int main() {
    int length = 0;
    int temp = 0;

    do {
        length = get_int("Height: ");
    }while(length <= 0);

    for (int i = 0; i < length; i++) {
        temp = length - i;
        for (int k = temp - 1; k > 0; k--) {
            printf(" ");
        }

        for (int j = 0; j <= i; j++) {
            printf("#");
        }

        for (int a = 0; a < 2; a++) {
            printf(" ");
        }

        for (int b = 0; b <= i; b++) {
            printf("#");
        }

        printf("\n");
    }
}
