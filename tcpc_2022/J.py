def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]

def solve():
    n, x = read_list()
    h = read_list()
    result = [0] * n
    for i in range(n):
        if h[i] < x:
            result[i] = 1
    print(' '.join(map(str, result)))   


for i in range(read()):
    solve()
