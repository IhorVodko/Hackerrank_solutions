#Problem: https://www.hackerrank.com/challenges/the-birthday-bar/problem


def birthday(s, d, m):
    start = 0
    end = m
    c = 0
    while end <= len(s):
        if sum(s[start:end])==d:
            c+=1   
        start+=1
        end+=1
    return c
