#Problem: https://www.hackerrank.com/challenges/s10-mcq-6/problem


from itertools import permutations

bag = ['r']*3 + ['b']*4
bag_all_options_2 = [*permutations(bag, 2)]
bag_1st_red = [x for x in bag_all_options_2 if x[0] == 'r']
bag_1st_red_2nd_blue = [x for x in bag_1st_red if x[1] == 'b']
solution = len(bag_1st_red_2nd_blue) / len(bag_1st_red)
print(round(solution, 4))
