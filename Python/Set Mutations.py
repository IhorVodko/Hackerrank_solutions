#Problem: https://www.hackerrank.com/challenges/py-set-mutations/problem


num_el = int(input())

s1 = set(input().split())
for _ in range(int(input())):
    
    operation, num_el = input().split()
    s2 = set(input().split())
    eval(f"s1.{operation}(s2)")

print(sum(map(int, s1)))
