#Problem: https://www.hackerrank.com/challenges/re-start-re-end/problem


import re

string = input().strip()
pattern = re.compile(input().strip())
    
match = pattern.search(string)

if not match:
    
    print((-1, -1))
    
while match: 
    
    start = match.start()
    end = match.end() - 1
    print((start, end))
    match = pattern.search(string, start+1 )
