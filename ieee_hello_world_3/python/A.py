def read():
    return int(input())
def reada():
    return [int(i) for i in input().split()]
 


def solve():
    n, q = reada()
    x = [0] + reada()
    for i in range(q):
        t, a, b = reada()
        if t == 1: 
            x[a] = b
        else:
            print(abs(x[a]-x[b]))


solve()