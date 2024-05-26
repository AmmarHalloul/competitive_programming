
def read():
    return int(input())
def reada():
    return [int(i) for i in input().split()]


def count(s):
    l = s.split('+')
    d = {}
    for i in l:
        m = 1
        start = 0 
        if i[0].isdigit():
            m = int(i[0])
            start = 1
        for j in range(start, len(i)):
            if i[j].isdigit():
                d[i[j-1]] += m * (int(i[j])-1)
            else:
                d[i[j]] = d.get(i[j], 0) + m
    # print(d)
    return d

    
def solve(s):
    j = 0
    while s[j] != '>':
        j += 1
    
    return count(s[:j-1]) == count(s[j+1:])

for i in range(read()):
    if solve(input()):
        print("DA")
    else:
        print("NE")
