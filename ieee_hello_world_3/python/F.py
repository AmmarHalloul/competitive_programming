
def read():
    return int(input())
def reada():
    return [int(i) for i in input().split()]
 


def solve(d):
    for c in d:
        if int(c) % 2 != 0:
            return False
    return True



for i in range(read()):    
    if solve(input()):
        print("Yes")
    else:
        print("No")