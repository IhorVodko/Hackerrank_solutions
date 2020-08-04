#Problem: https://github.com/IhorVodko/Hackerrank_solutions/edit/master/Python/Exceptions.py


# Enter your code here. Read input from STDIN. Print output to STDOUT
n = int(input().strip())

for _ in range(n):
    try:
        num1, num2 = map(int, input().split())
        print(num1//num2)
    except BaseException as e:
        print(f'Error Code: {e}')
    
