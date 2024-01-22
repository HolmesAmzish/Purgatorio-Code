# Problem name: Word
# Problem tags: implementation, strings
# Solve time:   2024.1.16
# Author:       Nulla

def convert(word):
    uppercaseCount = sum(1 for char in word if char.isupper())
    lowercaseCount = len(word) - uppercaseCount

    if uppercaseCount > lowercaseCount:
        correctWord = word.upper()
    else:
        correctWord = word.lower()
    
    return correctWord

word = input().strip()

print(convert(word))