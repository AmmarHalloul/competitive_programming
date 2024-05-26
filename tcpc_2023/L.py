
def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]
 


def solve():
    n = read();
    s = input()
    f = [False] * (ord('z')+2)
    min_c = s[0]
    max_c = s[0]
    for i in s:
        min_c = min(i, min_c)
        max_c = max(i, max_c)
        f[ord(i)] = True
    


    for i in s:
        if i != min_c and i != max_c and not (f[ord(i)+1] and f[ord(i)+1]):
            print("NO")
            return
    print("YES") 


for _ in range(read()):
    solve()