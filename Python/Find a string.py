#Problem: https://www.hackerrank.com/challenges/find-a-string/problem


def count_substring(string, sub_string):

    len_str = len(string)
    len_sub_str = len(sub_string)
    solution = sum([1 for i in range(len_str-len_sub_str+1) 
                        if string[i : i+len_sub_str]== sub_string])
    return solution


if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)
