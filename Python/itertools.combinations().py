#problem: https://www.hackerrank.com/challenges/itertools-combinations/problem


from itertools import combinations

string, length =  input().split(' ')
string  = sorted(string)
length  = int(length)

for k in range(1, length+1):
    for comb in list(combinations(string, k)):
        print(''.join(comb))
