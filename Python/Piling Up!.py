#Problem: https://www.hackerrank.com/challenges/piling-up/problem


for j in range(int(input())):
    input()
    list_ = list(map(int, input().split()))
    l  = len(list_)
    i = 0
    while i < l-1 and list_[i] >= list_[i+1]:
        i += 1 
    while i < l-1 and list_[i] <= list_[i+1]:
        i +=1
    if i == l-1:
        print('Yes')
    else:
        print('No')
