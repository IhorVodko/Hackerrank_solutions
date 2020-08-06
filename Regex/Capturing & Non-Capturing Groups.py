#Problem: https://www.hackerrank.com/challenges/capturing-non-capturing-groups/problem


Regex_Pattern = r'(ok){3}'	# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
