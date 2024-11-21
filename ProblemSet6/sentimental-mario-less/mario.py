from cs50 import get_int

while True:
    height = get_int("Height: ");
    if (1 <= height <= 8):
        break

for i in range(0, height):
    for _ in range(height - 1 - i):
        print(" ", end = "")
    for _ in range(i + 1):
        print("#", end = "")

    print()
