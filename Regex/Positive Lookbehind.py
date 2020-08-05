#Problem: https://www.hackerrank.com/challenges/positive-lookbehind/problem


Regex_Pattern = r"(?<=[1,3,5,7,9])\d"	# Do not delete 'r'.

import re

Test_String = input()

match = re.findall(Regex_Pattern, Test_String)

print("Number of matches :", len(match))
