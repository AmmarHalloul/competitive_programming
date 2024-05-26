def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]
 

maxv = 10**6

def solve():
    n = read()
    a = read_list()
    a.sort()

    freq = [0] * (maxv+1) 

    for i in a:
        freq[i] += 1

    x = a[0]
    y = a[-1]
    freq[x] -= 1
    freq[y] -= 1

    if n == 2:
        print('YES')
        return

    for z in a[1:-1]:
        w = y - z + x
        if (w != z and freq[w] > 0) or (w == z and freq[w] > 1):
            print('YES')
            return
    print('NO')

for _ in range(read()):
    solve()
