#include <stdio.h>
#include <cs50.h>

int main() {
    int length = 0;
    int temp = 0;
    do {
        length = get_int("Height: ");
    }while(length <= 0);

    for (int i = 0; i < length; i++) {
        // length每个循环都不会变，所以要创建一个中间变量让他每行减一
        temp = length - i;
        for (int k = temp - 1; k > 0; k--) {
            printf(" ");
        }

        for (int j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}