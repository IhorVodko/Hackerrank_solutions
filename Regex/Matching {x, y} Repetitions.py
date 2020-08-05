#Problem: https://www.hackerrank.com/challenges/matching-x-y-repetitions/problem


Regex_Pattern = r'^\d{1,2}[a-zA-Z]{3,}\.{,3}$'	# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
