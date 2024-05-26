def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]


def solve():
    n = read()
    a = read_list()

    incr = False
    last = 1000000
    bt = []
    for i in a:
        if incr and i < last:
            incr = False
        elif not incr and i > last:
            incr = True
            bt.append(last)
        last = i

    print(max(bt))



solve()