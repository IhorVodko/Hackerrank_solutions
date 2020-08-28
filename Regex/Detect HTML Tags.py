#problem: https://www.hackerrank.com/challenges/detect-html-tags/problem


import re, sys

matches = re.findall('(?<=<)\w+', sys.stdin.read())
print(';'.join(sorted(set(matches))) )
