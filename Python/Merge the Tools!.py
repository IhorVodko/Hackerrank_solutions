#Problem https://www.hackerrank.com/challenges/merge-the-tools/problem
#Score   40


def merge_the_tools(string, k):
    # your code goes here
    for par in zip(*[iter(string)]*k):
        d = dict()
        print(''.join([d.setdefault(j,j) for j in par if j not in d]))
