#Problem: https://www.hackerrank.com/challenges/py-introduction-to-sets/problem


def average(array):
    # your code goes here
    average = sum(set(array)) / len(set(array))
    return average

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)
