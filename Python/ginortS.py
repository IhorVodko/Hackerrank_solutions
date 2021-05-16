#problem: https://www.hackerrank.com/challenges/ginorts/problem


# Enter your code here. Read input from STDIN. Print output to STDOUT
print(*sorted(input(), key = lambda char: (-ord(char)>>5,   char in '02468', char)), sep = '')
