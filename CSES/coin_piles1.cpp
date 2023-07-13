#include<iostream>
#include<algorithm>
using namespace std;
void solve()
{   
    long long a,b;
    cin>>a>>b;
    if(2*min(a,b)<max(a,b)) cout<<"NO\n";
    else{
        a%=3,b%=3;
        if(a>b) swap(a,b);
        if((a==0 and b==0) or (a==1 and b==2))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
int main()
{   
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
