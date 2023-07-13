n=int(input())
a=list(map(int,input().split()))
st={}
st=set()
res=0
j=0
for i in range(n):
    while j<n and (a[j] not in st):
        st.add(a[j])
        j+=1
    cnt=j-i
    res+=(cnt*(cnt+1))//2
    st.discard(a[i])
print(res)

