#Problem: https://www.hackerrank.com/challenges/matching-same-text-again-again/problem


Regex_Pattern = r'^([a-z])(\w)(\s)(\W)(\d)(\D)([A-Z])([a-zA-Z])([aeiouAEIOU])(\S)\1\2\3\4\5\6\7\8\9\10$'	# Do not delete 'r'.

# ^([a-z]\w\s\W\d\D[A-Z][a-z,A-Z][aieouAEIOU]\S)\1$'
import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
