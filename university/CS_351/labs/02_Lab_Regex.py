# Python Lab 2 - Regex in Python
# King, CS 351, 02/12/2021

# ========================================
# Task 1: Pattern matching for strings
# ========================================
# 1. Define 10 string variables that follow the requirements given in Week 2's regular expression exercise. Some
# patterns might show up more than once. Some strings might not fit into any pattern. Some strings might fit into
# multiple patterns. An example list:
#     [“22.11”, “23”, “66.7f”, “123abcde”, “Case44”, “Happy”, ”78”, “66.7”, “yes123”, ”Book111”]
# 2. Write down the regular expressions for these patterns.
# 3. For each string, use if-elif-else and re library to test which pattern matches this string. Note that some strings
# might fit into multiple patterns.
# 4. Print out formatted output messages for the pattern matching results. For example: Str1 = ”22.11”. Test this string
# against different regular expression patterns until a match is found, then print a message out. Example output:
#     “22.11 matches the pattern: A float consists of 1 or more digits before and after decimal point.”
#     “22.11 matches the pattern: A float with exactly 2 digits after the decimal point.”
#     “23 matches the pattern: An integer”
# ========================================
# Task 2: Remove a part of a string
# ========================================
# Write a function that will find the int number at the beginning of a long string and remove it from the long string.
# Note that the integer might have space or no space following it (which function can you use to remove part of a
# string from a long string?). For example:
#     Testing string “22   street” will give output “Found integer 22 at the beginning of this string, starting at index
#     _ ending at index _. The rest of the string is:    street.”
#     Testing string “90years” will give “Found integer 90 at the beginning of this string, starting at index _ ending
#     at index _. The rest of the string is: years.”
# ========================================

import re  # regex library


def match_string(str):
    # For Task 1. Prints each string from a list which matches a particular regex pattern.
    # param str: a string which may fit into one or more regex pattern defined in this function.
    # output: "[element] matches the pattern: [regex pattern description]".
    out = "matches the pattern: "
    outlen = len(out)  # length of out will increase if a regex pattern match is found

    if re.match(r'\d+', str):
        out += "An integer. "  # trailing space in the case of multiple matches
    if re.match(r'\d+\.\d+', str):
        out += "A float consisting of 1 or more digits before and after decimal point. "
    if re.match(r'\d+\.\d{2}', str):
        out += "A float with exactly 2 digits after the decimal point. "
    if re.match(r'\d+\.\d+[f]', str):
        out += "A float ending with a single letter 'f' (e.g. '4.321f'). "
    if re.match(r'[A-Z]+[a-z]+\d+', str):
        out += "Uppercase letters, followed by lowercase letters, followed by digits. "
    if re.match(r'\d{3}\w{2,}', str):
        out += "Exactly 3 digits, followed by at least 2 letters. "

    if len(out) == outlen:
        out = "does not match any designated pattern."

    print(str, out)


def remove_string_part(longstr):
    # For Task 2. Finds and removes an integer at the beginning of a long string (if present).
    # param longstr: a string which may contain leading integer characters.
    # output: for a valid removal, "Found integer [int] at the beginning of this string, starting at index [start]
    #         and ending at index [end]. The rest of the string is: [remaining string]."
    matchint = re.match(r'\d+', longstr)
    if matchint is not None:
        print("Found integer", matchint.group(0), "at the beginning of this string, starting at index",
              matchint.start(), "and ending at index", matchint.end(), end=' ')
        longstr = longstr[matchint.end():]  # re-assign string value starting from found end index
        print("The rest of the string is:", longstr)
    else:
        print("No leading integer found in string", longstr)


if __name__ == '__main__':
    print("===== Task 1 =====")
    strlist = ['22.11', '23', '66.7f', '123abcde', 'Case44', 'Happy', '78', '66.7', 'yes123', 'Book111']
    for str in strlist:
        match_string(str)

    print("\n===== Task 2 =====")
    strlist2 = ['22   street', '90years', 'king', 'cougar9', '45.67 miles']
    for str in strlist2:
        remove_string_part(str)

