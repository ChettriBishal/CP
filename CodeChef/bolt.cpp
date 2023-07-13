#include<bits/stdc++.h>
using namespace std;
double rnd(double val) // rounding off to two decimal places
{
    char s[40];
    sprintf(s,"%.2lf",val);
    sscanf(s,"%lf",&val);
    return val;
}
void solve()
{
    double a,b,c,v;
    cin>>a>>b>>c>>v;
    v*=(a*b*c);
    double g=rnd(100/v);
    //cout<<g<<endl;
    if(g<9.58)
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
