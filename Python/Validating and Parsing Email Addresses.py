#Problem: https://www.hackerrank.com/challenges/validating-named-email-addresses/problem


import email.utils as eu
import re

for _ in range(int(input())):
    
    string = eu.parseaddr(input())
    pattern = r'^[A-Za-z]+[\w\.-]+@[A-Za-z]+\.[A-Za-z]{1,3}$'
    
    if re.match(pattern, string[1]):
        print(eu.formataddr(string))
    
