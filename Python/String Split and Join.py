#Problem: https://www.hackerrank.com/challenges/python-string-split-and-join/problem


def split_and_join(line):
  
    # write your code here
    line_splitted = line.split(" ")
    line_joined = "-".join(line_splitted)

    return line_joined


if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)
