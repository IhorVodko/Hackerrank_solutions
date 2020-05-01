#Problem: https://www.hackerrank.com/challenges/sock-merchant/problem


def sockMerchant(n, ar):
    dic = {}
    for i in ar:
        if  i in dic.keys():
            dic[i] +=1
        else:
            dic[i] = 1
    return  sum([p//2 for p in dic.values()])
