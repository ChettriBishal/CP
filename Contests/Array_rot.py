mod=1000000007
n=int(input())
a=list(map(int,input().split()))
res=sum(a)
res%=mod
q=int(input())
temp=list(map(int,input().split())) # to store the queries which is technically useless
for i in temp:
    res+=res
    res%=mod
    print(res)
