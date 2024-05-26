
def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]


def solve():
    n = read()
    l = sorted([read_list() for i in range(n)])
    last_hit = [-1000] * 9
    players = [0] * 9

    for time, a, b in l:
        players[a] += 100
        if time - last_hit[a] <= 10:
            players[a] += 50
        last_hit[a] = time
    print(sum(players[1:5]), sum(players[5:]))
    
    


solve()

# E G H I 