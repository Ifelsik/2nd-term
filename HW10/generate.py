from random import randint

with open("input.txt", "w+") as file:
    min = -65536
    max = 65536
    total_numbers = 10000
    for i in range(total_numbers):
        file.write(f"{randint(min, max)}\n")
    print("OK")
