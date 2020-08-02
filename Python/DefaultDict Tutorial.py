#Problem: https://github.com/IhorVodko/Hackerrank_solutions/new/master/Python


# Enter your code here. Read input from STDIN. Print output to STDOUT

def solution(array_A, array_B):

    d = defaultdict(list)
    c = 1
    for key in array_A:
        d[key].append(c)
        c += 1
    for key in array_B:
        if d[key]:
            print(*d[key])
        else:
            print(-1)


if __name__ == '__main__':

    from collections import defaultdict

    n, m = map(int, input().strip().split())
    A = [input().strip() for _ in range(n)]     
    B = [input().strip() for _ in range(m)]
    
    solution(A, B)
