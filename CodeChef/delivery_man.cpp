#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define io ios_base::sync_with_stdio(false); \
cin.tie(NULL); \
cout.tie(NULL);
bool comp(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b)
{
	if(a.f>b.f)
		return true;
	else
		return false;
}
typedef long long ll;
int main()
{
	io
	int n,x,y;
	cin>>n>>x>>y;
	vector<int>a(n),b(n);
	vector<pair<int,pair<int,int>>>c; // to store the losses
	for(int &r:a)
		cin>>r;
	for(int &r:b)
		cin>>r;
	for(int i=0;i<n;i++)
		c.pb({abs(b[i]-a[i]),{a[i],b[i]}});
	
  sort(c.begin(),c.end(),comp); 
	for(int i=0;i<n;i++){  // sorting on the basis of array d
		a[i]=c[i].s.f;
		b[i]=c[i].s.s;
	}
	int andy=0,bob=0; // greater the difference larger is one value with respect to another (by that difference)
	ll res=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>b[i])
		{
			if(andy+1<=x){
				res+=a[i];
				andy++;
			}
			else{
				res+=b[i];
				bob++;
			}
		}
		else{
			if(bob+1<=y){
				res+=b[i];
				bob++;
			}
			else{
				res+=a[i];
				andy++;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}

/*
Let us denote D[i] = |A[i] - B[i]|. Now we will sort all the orders in decreasing order of D.
Now we will process the orders one by one.
We can have following two cases:

If A[i] > B[i], then we will try to assign it to Andy if possible (If after the assignment, limit of orders is not crossed).
Otherwise we will assign it to Bob.

If B[i] > A[i], then we will try to assign it to Bob if possible. Otherwise we will assign it to Andy.

Note that the condition X + Y >= n guarantees that we will be able to assign the order to one of the persons.

Proof of the Solution
Assume that for some i, A[i] > B[i] and you assigned order to Bob, loss encountered due to this assignment is D[i].
Similarly, for some i, B[i] > A[i] and you assigned order to Andy, loss encountered due to this assignment is D[i].

As we want to minimize the loss encountered, it is better to process the orders having high possible losses, because we can
try to reduce the loss in the starting part. There is no point of doing an order which is high loss after an order with less loss.
*/
