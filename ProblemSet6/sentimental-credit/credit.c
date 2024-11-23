from cs50 import get_int
import sys

def main():
    valid = False

    while True:
        num = get_int("Number: ")
        if (num > 0):
            break

    sum1 = get_odd_sum(num)
    sum2 = get_even_minus_two_sum(num)
    sum = sum1 + sum2
    valid = is_valid_sum(sum)
    length = count_num(num)

    if (valid):
        aMEX = is_AMEX(num, length)
        mASTERCARD = is_MASTERCARD(num, length)
        vISA = is_VISA(num, length)
        print_result(aMEX, mASTERCARD, vISA)
    else:
        print("INVALID")

def get_odd_sum(num):
    last_digit = 0
    sum = 0

    while (num > 0):
        last_digit = num % 10
        sum += last_digit
        num = num // 100

    return sum

def get_even_minus_two_sum(num):
    last_digit = 0
    sum = 0
    num = num // 10

    while (num > 0):
        last_digit = num % 10 * 2
        sum += (last_digit % 10) + (last_digit // 10)
        num = num // 100

    return sum

def is_valid_sum(sum):
    result = sum % 10
    if (result == 0):
        return True
    else:
        return False

def count_num(num):
    count = 0
    while (num > 0):
        count += 1
        num = num // 10

    return count

def is_AMEX(num, length):
    num //= 10000000000000
    if (length == 15):
        if (num == 34) or (num == 37):
            return True

    return False

def is_MASTERCARD(num, length):
    num = num // 100000000000000
    if (length == 16):
        if (51 <= num <= 55):
            return True

    return False

def is_VISA(num, length):
    if (length == 16):
        num = num // 1000000000000000
        if (num == 4):
            return True
    elif (length == 13):
        num = num // 1000000000000
        if (num == 4):
            return True

    return False

def print_result(AMEX, MASTERCARD, VISA):
    if (AMEX == True):
        print("AMEX")
    elif (MASTERCARD == True):
        print("MASTERCARD")
    elif (VISA == True):
        print("VISA")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
