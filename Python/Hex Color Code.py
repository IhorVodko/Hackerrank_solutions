#Problem: https://www.hackerrank.com/challenges/hex-color-code/problem


import re
import sys

[print(match) for line in sys.stdin \
    for match in re.findall('[\s:](#[a-f0-9]{6}|#[a-f0-9]{3})', line, re.I)]
