def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]

def solve():
    n, x = read_list()
    s = input()
    t = input()
    result = 0
    for i in range(n):
        j = (i+n-x%n)%n
        if t[i] != s[j]:
            result += 1
    print(result)


solve()
