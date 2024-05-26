def read():
    return int(input())
def read_list():
    return [int(i) for i in input().split()]


def solve():
    n = read()
    party = {}
    votes = {}
    for i in range(n):
        name = input()
        p = input()
        party[name] = p
        votes[name] = 0

    m = read()
    for i in range(m):
        t = input()
        if t in votes:
            votes[t] += 1
    
    l = sorted([(i, j) for j, i in votes.items()], reverse=True)
    if len(l) > 1 and l[0][0] == l[1][0]:
        print("Second round is required") 
    else:
        print(l[0][1], party[l[0][1]])
        
        



    


solve()