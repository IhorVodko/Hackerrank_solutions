#Problem: https://www.hackerrank.com/challenges/matching-specific-characters/problem


Regex_Pattern = r'^[123][120][xs0][30Aa][xsu][.,]$'	# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
