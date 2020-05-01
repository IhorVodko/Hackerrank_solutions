#Problem: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem


def breakingRecords(scores):
    min_ = max_ = scores[0]
    min_count = max_count = 0
    for i in scores[1:]:
        if i > max_:
            max_ = i
            max_count += 1
        if i < min_:
            min_count += 1
            min_ = i
    return max_count, min_count
