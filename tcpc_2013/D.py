def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]
 


mod = int(1e9+7)
max_n = int(1e6)


def solve():
    dp = [0] * (max_n+1)
    f = 1
    for i in range(2, max_n+1):
        f = (f*i) % mod
        dp[i] = (dp[i-1] + (((f + mod - dp[i-1]) % mod) * (i-1)) % mod) % mod 
    for i in range(read()):
        print(dp[read()])
solve()
