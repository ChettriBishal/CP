#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define io ios_base::sync_with_stdio(false); \
cin.tie(NULL); \
cout.tie(NULL);
typedef long long ll;
bool comp(pair<ll,ll>a1,pair<ll,ll>a2)
{
	if(a1.s>a2.s)
		return true;
	else if(a1.s==a2.s)
		if(a1.f>a2.f)
			return true;
	return false;
}
int main()
{
	io
	ll n;
	cin>>n;
	ll a1,a2,a3,pre=0;
	vector<pair<ll,ll>>a;
	for(int i=0;i<n;i++)
	{
		cin>>a1>>a2>>a3;
		a.pb({a1,a2+a3});
	}
	sort(a.begin(),a.end(),comp);
	vector<ll>bis;
	int val=0;
	for(int i=0;i<n;i++)
	{
		val+=a[i].f;
		bis.pb(val+a[i].s);
	}
	cout<<*max_element(bis.begin(),bis.end())<<endl;
	return 0;
}
/*
Here I have a question.

Let n = 2;

Let a1, d1 & a2, d2 be there timings(d = b + c)

if d1 > d2 and a1 + d1 < a2 + d2

Why do we complete a1 + d1 first , even when a2 + d2 is gonna take more time

So why are we only comparing d's over here and not caring about 'a'?

ANSWER:
In the example you give above, if you

send 1 first, then time for total completion of task = max(a1 + d1, a1+ a2 + d2) = a1+ a2 + d2 (since a1 + d1 < a2 + d2)

send 2 first, then time for total completion of task = max(a2 + d2, a2 + a1 + d1) = a2 + a1 + d1 (since d1 > d2)

So, you have to choose between a1+ a2 + d2 vs a2 + a1 + d1, i.e. d1 vs d2. :)

So the short answer is, after some dirty case by case analysis, it turns out that comparing d1 to d2 works in all cases. :)

The more intuitive way to see the same is as follows. The larger my d, the earlier I should go, even if earlier by a small amount. 

One of the d's is going to happen after (a1 + a2), and you want the smaller d to happen after.

*/




