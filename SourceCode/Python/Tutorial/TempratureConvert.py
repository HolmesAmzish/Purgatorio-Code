# File name: TempratureConvert.py
# Date: 2023/12/25

TempStr = input("Input the temprature with sign: ")
if TempStr[-1] in ['F', 'f']:
    C = (eval(TempStr[0 : -1]) - 32) / 1.8
    print("The temprature after convert: {:.2f}C".format(C))
    # Convert F to C
elif TempStr[-1] in ['C', 'c']:
    F = 1.8 * eval(TempStr[0 : -1]) + 32
    print("The temprature after convert: {:.2f}F".format(F))
    # Convert C to F
else:
    print("Invalid input")