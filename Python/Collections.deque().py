#Problem: https://www.hackerrank.com/challenges/py-collections-deque/problem


from collections import deque

d = deque()
for _ in range(int(input())):
    operation = input().split() + ['']
    eval(f'd.{operation[0]}({operation[1]})')

print(*d)
