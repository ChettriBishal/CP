#include<iostream>
#include<vector>
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	ll sum=(ll)n*(n+1)/2;
	vector<int>a,b;
	if(sum&1)
		cout<<"NO\n";
	else{
		cout<<"YES\n";
		sum/=2;
		while(n){
			if(sum-n>=0){
				a.pb(n);
				sum-=n;
			}
			else
				b.pb(n);
			n--;
		}
		cout<<a.size()<<endl;
		for(int x:a)
			cout<<x<<" ";
		cout<<endl<<b.size()<<endl;
		for(int x:b)
			cout<<x<<" ";
	}
	return 0;
}
