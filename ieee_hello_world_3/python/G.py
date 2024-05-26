
def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]


def solve():
    n = read()
    if n % 2 == 1:
        print("Either")
    else:
        if (n//2) % 2 == 0:
            print("Even")
        else:
            print("Odd")
    


solve()

# G