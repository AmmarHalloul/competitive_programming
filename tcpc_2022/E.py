def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]

def solve():
    n = read()
    count = [0] * (n+1)
    for i in range(n):
        for j in read_list()[1:]:
            count[j] += 1

    result = []
    for i in range(1, n+1):
        if count[i] > n//2:
            result.append(i)
    print(len(result))
    print(' '.join(map(str, result)))


for i in range(read()):
    solve()
