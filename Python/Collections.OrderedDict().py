#problem: https://www.hackerrank.com/challenges/py-collections-ordereddict/problem


from collections import OrderedDict

ord_dict = OrderedDict()
for _ in range(int(input())):
    item, rest, quant = input().rpartition(' ')
    ord_dict[item] = ord_dict.get(item, 0) + int(quant)

[print(item, quantity) for item, quantity in ord_dict.items()]
