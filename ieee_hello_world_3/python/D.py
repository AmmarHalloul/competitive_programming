def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]


def solve():
    n = read()
    a = sorted([read_list() for i in range(n)], key=lambda x: x[1])
    result = 0
    l = 0
    r = n-1
    while l <= r:
        result = max(result, a[l][1]+a[r][1])
        if a[l][0] > a[r][0]: 
            a[l][0] -= a[r][0] 
            r -= 1
        elif a[l][0] < a[r][0]:
            a[r][0] -= a[l][0] 
            l += 1
        else:
            l += 1
            r -= 1
    return result
    


# for i in range(read()):   
print(solve())

# B D E G H I 