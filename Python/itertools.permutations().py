#Problme: https://github.com/IhorVodko/Hackerrank_solutions/new/master/Python


from itertools import permutations

string, length = input().strip().split()
solution = [''.join(perm) for perm in permutations(sorted(string), int(length))]

print(*solution, sep = '\n')
