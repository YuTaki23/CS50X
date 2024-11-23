#include <stdio.h>
#include <cs50.h>

int calculate_nums(int cent, int nums);

int main() {
    int cent = 0;
    int result = 0;
    do {
        cent = get_int("Changer owed: ");
    } while (cent < 0);

    // 25cent
    int twenty_five = calculate_nums(cent, 25);
    cent -= 25 * twenty_five;

    // 10cent
    int ten = calculate_nums(cent, 10);
    cent -= 10 * ten;

    // 5cent
    int five = calculate_nums(cent, 5);
    cent -= 5 * five;

    // 1cent
    int one = calculate_nums(cent, 1);
    cent -= 1 * one;

    result = twenty_five + ten + five + one;

    printf("%d\n", result);
    return 0;
}

int calculate_nums(int cent, int nums) {
    int result = 0;
    while (cent >= nums) {
        result++;
        cent -= 25;
    }
    return result;
}
