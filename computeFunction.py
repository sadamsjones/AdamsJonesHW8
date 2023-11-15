import math

def compute_function(x):
    return x**2 + 2;

def main():
    print("Values for f(x) = x^2 + 2 for x in the range [0, 9]:")
    #int vals = range(10); #0 to 10 
    for x in range(10):
        result = compute_function(x)
        #print("f(x) = " + rseult)
        print(result)
