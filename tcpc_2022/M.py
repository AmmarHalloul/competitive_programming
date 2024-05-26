
def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]

def solve():
    n = read()
    m = n 
    while m%2==0: 
        m//=2
    if m == 1: 
        print(-1)
    else:
        x = m//2
        y = m//2+1
        p = n//m
        l = x-p+1n
        r = y+p-1
        if l <= 0:
            l = -l+1
        print(l, r)

for i in range(read()):
    solve()
