#Problem: https://github.com/IhorVodko/Hackerrank_solutions/new/master/Regex


Regex_Pattern = r'^\d\w{4}\.$'	# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
