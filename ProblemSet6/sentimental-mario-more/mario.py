from cs50 import get_int

while True:
    height = get_int("Height: ");
    if (1 <= height <= 8):
        break

for i in range(height):
    for _ in range(height - i - 1):
        print(" ", end = "")
    for _ in range(i + 1):
        print("#", end = "")
    for _ in range(2):
        print(" ", end = "")
    for _ in range(i + 1):
        print("#", end = "")
    print()
