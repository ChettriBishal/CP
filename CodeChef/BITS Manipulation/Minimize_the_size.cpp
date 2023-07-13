#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void solve()
{
   ll c;
   cin>>c;
   ll curr = 0; // current xor
   vector<ll> res; // resultant array
   for(int i= 60;i>= 0;i--){
       ll bit = (1ll<< i);
       if(( c& bit ) != (curr & bit)){ // if the bits are NOT same at these positions 
           res.push_back((1ll << (i+1))-1);
           curr ^= (1ll << (i+1)) -1;
       }
   }
   if(c == 0){
       res = {1,1};
   }
   cout<<res.size()<<endl;
   for(auto &k: res)
       cout<<k<<" ";
   cout<<endl;
	
}

signed main()
{
	#ifdef Bis
        freopen("input.txt","r",stdin);
	#endif
    io;
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

