
import random


def generate_numbers(file_name, length, rng=214748364):
    f = open(file_name, "a")
    for i in range(length-1):
        f.write(str(random.random()*(rng)-rng/2) + " ")
    f.write(str(random.random()*(rng)-rng/2))
    f.close()


def createFiles(name, elements, number=100):
    for i in range(number):
        generate_numbers(name + "-" + str(i)+".txt", elements)


def main():
    for i in range(1, 6):
        createFiles("input-"+str(10**i), 10**i)


if __name__ == "__main__":
    main()
