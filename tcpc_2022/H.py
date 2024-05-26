def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]

def solve():
    n, m, a = read_list()
    print(min(n-m, a))


for i in range(read()):
    solve()
