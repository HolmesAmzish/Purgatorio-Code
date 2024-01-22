# Problem name: Boy or Girl
# Problem tags: brute force, implementation, strings
# Solve time:   2024.1.14
# Author:       Nulla

username = input().strip()

# Count the number of distinct charachters
distinct_characters = set(username)

# Determine the gender based on the count
if len(distinct_characters) % 2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")