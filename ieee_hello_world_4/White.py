def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]


def solve():
    t = read()
    for _ in range(t):
        x,n = read_list()
        fn = n
        if n >= 3:
            fn = n*2-2
        
        t_div = x//fn

        r = [t_div]*fn

        for i in range(x%fn):
            r[i%fn] += 1
            
        if fn >= 3:
            for i in range(n-2):
                r[i+1]+=r[-i-1]

        print(" ".join([str(x) for x in r[:n]]))
    


solve()