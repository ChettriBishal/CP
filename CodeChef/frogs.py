for _ in range(int(input())): 
	n=int(input())
	w=list(map(int,input().split()))
	l=list(map(int,input().split()))
	pos=list(i for i in range(n)) #storing the current position of the frogs
	w2=sorted(w) # the sorted form that we want relative to which we are gonna check
	cnt=0
	for i in range(1,n):
		ind=w.index(w2[i]) # getting index from sorted array
		back=pos[w.index(w2[i-1])] # position of the frog having one step less weight than the current one
		temp=ind
		while temp<=back: #if frog having more weight lies before the one having less weight 
			temp+=l[ind] #jumping 
			pos[ind]=temp # new index of the frog 
			cnt+=1
	print(cnt)


		







		
