#Problem: https://www.hackerrank.com/challenges/nested-list/problem


if __name__ == '__main__':
    list_ = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        list_.append([name, score])

second_lowest  = sorted(list(set([x[1] for x in list_])))[1]
print('\n'.join([x[0] for x in sorted(list_) if x[1] == second_lowest]))
