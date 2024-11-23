from cs50 import get_float

def main():
    while True:
        cent = get_float("Change: ")
        if (cent >= 0):
            break
    cent *= 100
    cent = int(cent)


    twenty_five = calculate_nums(cent, 25)
    cent = cent - 25 * twenty_five

    ten = calculate_nums(cent, 10)
    cent = cent - 10 * ten

    five = calculate_nums(cent, 5)
    cent = cent - 5 * five

    one = calculate_nums(cent, 1)
    cent = cent - 1 * one

    result = twenty_five + ten + five + one
    print(f"{result}")

    return 0


def calculate_nums(cent, nums):
    result = 0
    while (cent >= nums):
        result += 1
        cent -= nums
    return result

if __name__ == "__main__":
    main()
