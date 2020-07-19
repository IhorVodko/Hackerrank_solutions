#Problme: https://www.hackerrank.com/challenges/designer-door-mat/problem


n, m = map(int, input().split())

pattern_1 = [('.|.'*(2*i+1)).center(m, '-') for i in range(n//2)]
pattern_2 = 'WELCOME'.center(m, '-')

print('\n'.join(pattern_1 + [pattern_2] + pattern_1[::-1]))
