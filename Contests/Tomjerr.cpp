#include<iostream>
using namespace std;
void solve()
{
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;

    int dist=abs(a-c)+abs(d-b);

    if(k>=dist and (k-dist)%2==0)
        cout<<"YES\n";
    else
        cout<<"NO\n";

}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;

}
