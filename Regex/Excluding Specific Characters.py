#Problem: https://www.hackerrank.com/challenges/excluding-specific-characters/problem


Regex_Pattern = r'^\D[^aeiou][^bcDF]\S[^AEIOU][^.,]$'	# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
