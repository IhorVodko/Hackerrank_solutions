#Problem: https://www.hackerrank.com/challenges/bon-appetit/problem


def bonAppetit(bill, k, b):

    count = 0
    for i in range(len(bill)):
        if i != k:
            count+=bill[i]
    pay = count//2
    if pay == b:
        print('Bon Appetit')
    else:
        print(int(b-pay))
