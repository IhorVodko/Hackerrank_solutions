#Problem: https://www.hackerrank.com/challenges/find-substring/problem


import re

n = int(input())
str_list = [input() for _ in range(n)]

q = int(input())
for _ in range(q):
    num = 0
    sub = input()
    for str_ in str_list: 
        num +=  len(re.findall('\w'+sub+'\w', str_))
    print(num)
