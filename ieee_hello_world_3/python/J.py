
def read():
    return int(input())
def reada():
    return [int(i) for i in input().split()]


def solve():
    n, s = input().split()
    n = int(n)
    if len(s) == n:
        print("YES")
    else:
        print("NO")



    
solve()