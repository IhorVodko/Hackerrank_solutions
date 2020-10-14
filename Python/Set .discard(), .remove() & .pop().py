#Problem: https://www.hackerrank.com/challenges/py-set-discard-remove-pop/problem


n = int(input())
s = set(map(int, input().split()))

for _ in range(int(input())):
    com = input().split()+['']
    eval(f's.{com[0]}({com[1]})')

print(sum(s))
