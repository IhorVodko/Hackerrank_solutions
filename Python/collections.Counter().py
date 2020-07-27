#Problem: https://www.hackerrank.com/challenges/collections-counter/problem


def revenue(sizes, size_price):

    sizes_count = Counter(sizes)
    revenue = 0
    for item in size_price:
        if sizes_count.get(item[0], 0) != 0:
            revenue += item[1]
            sizes_count.update({item[0]: -1})

    print(revenue)

    
if __name__ == '__main__':

    from collections import Counter

    num_sizes = int(input().strip())
    sizes = [*map(int, input().strip().split())]
    num_cast = int(input().strip())
    size_price = []
    for _ in range(num_cast):
        size_price.append([*map(int, input().strip().split())])
    
    revenue(sizes, size_price)

