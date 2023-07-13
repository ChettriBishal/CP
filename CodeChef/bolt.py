for _ in range(int(input())):
    a,b,c,v=map(float,input().split())
    v=v*a*b*c
    v=100/v
    v=round(v,2)
    #print(v)
    if v<9.58:  
        print("YES\n")
    else:
        print("NO\n")
