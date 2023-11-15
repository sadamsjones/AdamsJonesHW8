import math

def cube_function(x):
    return x**3

def main():
    print("Cube of odd numbers from 0 to 19 or the numbers themselves if they are even")
    for x in range(20):
        if x % 2 == 1:
            cube = x**3
        else:
            cube = x
            print("Values cubed:")
            print(cube)
