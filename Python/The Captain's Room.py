#Problem: https://www.hackerrank.com/challenges/py-the-captains-room/problem


k = int(input())
room_nums = list(map(int, input().split()))

set_room_nums = set(room_nums)
cap_room = ((sum(set_room_nums)*k - sum(room_nums)) // (k-1))

print(cap_room)
