def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]
 


def solve():
    n = read()
    s = list(input())


    for i in range(n//2):
        r = n-i-1
        if s[r] == 'C' or s[i] == 'C':
            s[i] = 'B'
            s[r] = 'B'
        else:        
            s[i] = 'A'
            s[r] = 'A'
            

    if n%2==1:
        if s[n//2] == 'B':  
            s[n//2] = 'A'
        elif s[n//2] == 'C':  
            s[n//2] = 'B'

    print(''.join(s))

for _ in range(read()):
    solve()