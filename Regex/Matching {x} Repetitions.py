#Problem: https://github.com/IhorVodko/Hackerrank_solutions/new/master/Regex


Regex_Pattern = r'^[a-zA-z02468]{40}[13579\s]{5}$'	# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
