#include<bits/stdc++.h>
#define int long long
#define s second
using namespace std;
void solve(int c)
{
    int n,k,b,t;
    cin>>n>>k>>b>>t;
    vector<int>loc(n),spd(n);
    for(int &x:loc)// initial location of the chicks
        cin>>x;
    for(int &x:spd) // speeds of the chicks
        cin>>x;
    int cnt=0,res=0,swap=0;
    for(int i=n-1;i>=0;i--) // moving from the back farthest away
    {
        int dist=b-loc[i]; // distance that the chick "has" to cover
        int chick_dist=t*spd[i]; // distance that the chick "can" cover in time t
        if(dist<=chick_dist)// if it can cover 
        {
            cnt++; // those chickens who can cover
            res+=swap; // all slow chickens at front should allow overtake
        }
        else swap++;
        if(cnt==k)
            break;
    }
    cout<<"Case #"<<c<<": ";
    if(cnt==k)
        cout<<res<<"\n";
    else
        cout<<"IMPOSSIBLE\n";
}
int32_t main()
{
    int tests;
    cin>>tests;
    for(int i=1;i<=tests;i++)
        solve(i);
    return 0;
}
/*
 *  Initially I did with respect to time but in doing so...
 *  the error was that distance/speed rounds off time hence gives incorrect answers
 *  So the criteria to be greedy upon is the distance that chick can cover vs what it has to cover
 */
