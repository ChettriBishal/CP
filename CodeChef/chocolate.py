for _ in range(int(input())):
    n,x=map(int,input().split())
    bis=list(map(int,input().split()))
    print(min(n-x,len(set(bis)))) #len(set(bis)) gives the length of the set...aka no of unique elements in list
 
