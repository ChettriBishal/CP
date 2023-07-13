#include<bits/stdc++.h>
using namespace std;

void solve()
{
   int n;
   cin>>n;
   long a[n];
   for(long & x: a) cin>>x;
  
   sort(a,a+n);
   int cnt = count(a,a+n,a[0]);
   for(int i=1;i<n;i++){
       if(a[i]== a[0] || ceil((double)a[i]/2.0)-1 >= a[0]) 
           continue;
       else{
           cout<<n<<endl;
           return;
       }
   }
   cout<<n - cnt<<endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
// https://www.codechef.com/problems/MODEQUAL
