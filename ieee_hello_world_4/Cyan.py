def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]


def solve():
    n,k = read_list()
    sn = read_list()
    
    s = 0

    for i in sn:
        s += i//k

    print(s)


solve()