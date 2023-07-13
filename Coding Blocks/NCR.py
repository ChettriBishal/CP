import math
def nCr(n,r):
    f=math.factorial
    return f(n)// f(r) // f(n-r)
for _ in range(int(input())):
    n,k=map(int,input().split())
    print(math.trunc(nCr(n-1,k-1)))
