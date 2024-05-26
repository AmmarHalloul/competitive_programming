def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]
 


mod = int(1e9+7)

def calc(s):
    ret = 1
    n = len(s)
    for i in range(n//2):
        r = n-i-1
        if s[r] == '?' and s[i] == '?':
            ret *= 26
            ret %= mod
        elif s[r] != '?' and s[i] != '?' and s[i] != s[r]:
            return 0
    if n%2==1 and s[n//2] == '?':
        ret *= 26
        ret %= mod
    return ret


def solve():
    n = read()
    s = input()
    equal = 0
    char_count = 0
    exist = [False] * (ord('z')+1)
    for i in s:
        if not exist[ord(i)]:
            char_count += 1
            exist[ord(i)] = True

    if exist[ord('?')]:
        if char_count == 1:
            equal = 26
        elif char_count == 2:
            equal = 1

    result = calc(s)
    if len(s) > 1:
        result = (result + calc(s[1:]+s[0])) % mod
    print(result)
    result = (result + mod - equal) % mod

for _ in range(read()):
    solve()