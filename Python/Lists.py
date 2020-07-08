#Problem: https://www.hackerrank.com/challenges/python-lists/problem


n = int(input())
list_ = []
for _ in range(n):
    line = input().split()
    cmd = line[0]
    args = line[1:]
    if cmd != "print":
        cmd += "("+ ",".join(args) +")"
        eval("list_." + cmd)
    else:
        print(list_)


