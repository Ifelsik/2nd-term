from random import randint
with open("input.txt", "w+") as file:
    min = -2 ** 32
    max = 2 ** 32 -1
    numbers = 10 ** 5
    for i in range(numbers):
        file.write(f"{randint(min, max)}\n")
    print("OK")
