#Problem: https://www.hackerrank.com/challenges/itertools-product/problem


# Enter your code here. Read input from STDIN. Print output to STDOUT

def fun_cartesian(set_A, set_B):
    print(*product(set_A, set_B))

if __name__ == '__main__':
    from itertools import product

    set_A = [*map(int, input().strip().split())]
    set_B = [*map(int, input().strip().split())]

    fun_cartesian(set_A, set_B)
