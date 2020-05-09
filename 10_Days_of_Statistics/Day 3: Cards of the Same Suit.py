#Problem: https://www.hackerrank.com/challenges/s10-mcq-5/problem


from itertools import permutations

deck = [(suit, rank) for suit in ['a', 'b', 'c', 'd'] for rank in [*range(1,14)]]
all_options = [*permutations(deck, 2)]
correct_options = [card for card in all_options if card[0][0] == card[1][0]]
solution = len(correct_options)  / len(all_options)
print(round(solution, 4))
