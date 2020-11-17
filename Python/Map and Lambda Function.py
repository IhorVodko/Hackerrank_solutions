#Problem: https://www.hackerrank.com/challenges/map-and-lambda-expression/problem


cube = lambda x: x**3

def fibonacci(n):
    
    list_ = [0, 1]
    for i in range(2, n):
        list_.append(list_[i-2] + list_[i-1])
    
    return list_[0:n]

if __name__ == '__main__':
    n = int(input())
    print(list(map(cube, fibonacci(n))))
