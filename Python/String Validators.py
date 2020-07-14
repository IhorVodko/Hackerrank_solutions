#Problem: https://www.hackerrank.com/challenges/string-validators/problem


if __name__ == '__main__':
    s = input()

for check in ['isalnum', 'isalpha', 'isdigit', 'islower', 'isupper']:
    print( any([eval('char.' + check + '()') for char in s]) ) 
