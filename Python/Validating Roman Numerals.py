#Problem: https://www.hackerrank.com/challenges/validate-a-roman-number/problem


import re

thousand = 'M{0,3}'
hundred = '(C[MD]|D?C{0,3})'
ten = '(X[CL]|L?X{0,3})'
digit = '(I[VX]|V?I{0,3})'

regex_pattern = re.compile('^' + thousand + hundred+ten+digit +'$')	# Do not delete 'r'

print(str(bool(re.match(regex_pattern, input()))))
