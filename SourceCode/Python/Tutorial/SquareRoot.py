# File name:    Square root
# Description:  Calculate the square root of the number input
# Written date: 2024.1.8
# Author:       NULLA

import math
n = int(input("Please enter a number: "))
root = math.sqrt(n)
print("The square root of {:d} is {:.2f}".format(n,root))