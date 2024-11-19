#include <stdio.h>
#include <cs50.h>

int get_odd_sum(long num);
int get_even_minus_two_sum(long num);
bool is_valid_sum(int sum);
int count_num(long num);
bool is_AMEX(long num, int length);
bool is_MASTERCARD(long num, int length);
bool is_VISA(long num, int length);
void print_result(bool AMEX, bool MASTERCARD, bool VISA);

int main() {
    long num;
    int sum1, sum2, sum, length;
    bool valid = false;
    bool AMEX, MASTERCARD, VISA;

    //若输入的num小于0，则一定错误，无须继续判断，用do-while
    do {
        num = get_long("Number: ");
    } while (num <= 0);

    // 根据Luhn算法求是否合法
    sum1 = get_odd_sum(num);
    sum2 = get_even_minus_two_sum(num);
    sum = sum1 + sum2;
    valid = is_valid_sum(sum);

    length = count_num(num);

    if (valid) {
        AMEX = is_AMEX(num, length);
        MASTERCARD = is_MASTERCARD(num, length);
        VISA = is_VISA(num, length);
        print_result(AMEX, MASTERCARD, VISA);
    } else {
        printf("INVALID\n");
    }

    return 0;
}

int get_odd_sum(long num) {
    // 一直取最后一位数字 即取模 % 10
    // 将num不断除以100
    // 直到num < 0
    int last_digit = 0;
    int sum = 0;

    while (num > 0) {
        last_digit = num % 10;
        sum += last_digit;
        num /= 100;
    }
    return sum;
}

int get_even_minus_two_sum(long num) {
    int sum = 0;
    int last_digit = 0;
    num /= 10;

    while (num > 0) {
        last_digit = num % 10 * 2;
        // 若最后一位大于10则应分为两个部分 十位数 和 个位数
        sum += (last_digit % 10) + (last_digit / 10);
        num /= 100;
    }
    return sum;
}

bool is_valid_sum(int sum) {
    int result = sum % 10;
    if (!(result == 0)) {
        return false;
    } else {
        return true;
    }
}

int count_num(long num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}


bool is_AMEX(long num, int length) {
    num /= 10000000000000;
    if (length == 15) {
        if ((num == 34) || (num == 37)) {
            return true;
        }
    }
    return false;
}

bool is_MASTERCARD(long num, int length) {
    num /= 100000000000000;
    if (length == 16) {
        if ((num >= 51) && (num <= 55)) {
            return true;
        }
    }
    return false;
}

bool is_VISA(long num, int length) {
    if (length == 16) {
        num /= 1000000000000000;
        if (num == 4) {
            return true;
        }
    } else if (length == 13) {
        num /= 1000000000000;
        if (num == 4) {
            return true;
        }
    }
    return false;
}

void print_result(bool AMEX, bool MASTERCARD, bool VISA) {
    if (AMEX){
        printf("AMEX\n");
    } else if (MASTERCARD) {
        printf("MASTERCARD\n");
    } else if (VISA) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
}
