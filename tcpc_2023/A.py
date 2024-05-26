def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]




def z_fn(s):
    n = len(s)
    z = [0] * n
    x = 0
    y = 0
    for i in range(1, n):
        if i < y: 
            z[i] = min(z[i-x], y-i)
        while i+z[i] < n and s[z[i]] == s[i+z[i]]:
            z[i] += 1
        if i+z[i] > y:
            y = i+z[i]
            x = i
    return z

def solve():
    n = read()
    s = input()[::-1]
    z = z_fn(s)
    
    origin_len = 0
    added = 0
    i = 0
    while i < n:
        if z[i] == 0:
            origin_len += added + 1
            added = 0
            i += 1
        else:
            added += z[i] 
            i += z[i]

    s = s[::-1]
    s = s[:origin_len]
    n = len(s)
    if n == 0 or n%2==1:
        print(-1)
    else:
        print(n)
        print(s[:n//2])
        print(s[n//2:])


for _ in range(read()):
    solve()

	