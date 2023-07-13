# 20-Apr-21 6:26:26 PM
#Bishal
for _ in range(int(input())):
    n,r=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    res=b[0]
    check=res
    for i in range(1,n):
        check-=r*(a[i]-a[i-1])
        check=max(check,0)
        check+=b[i]
        res=max(check,res)
    print(res)
