#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
bool comp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b)
{
    if(a.s>b.s)
        return true;
    return false;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int &x:a)
        cin>>x;
    for(int &x:b)
        cin>>x;
    vector<pair<pair<int,int>,int>>s;
    
    for(int i=0;i<n;i++)
        s.push_back({{a[i],b[i]},a[i]+b[i]});
        
    sort(s.begin(),s.end(),comp); 
    
    /* cout<<"Sorted Greedily\n"; */
    /* for(int i=0;i<n;i++) */
    /*     cout<<s[i].f.f<<" "<<s[i].f.s<<" "<<s[i].s<<endl; */
    /* cout<<endl<<endl; */
    long long sa=0,sb=0;// their scores
    for(int i=1;i<=n;i++)
    {
        if(i&1) sa+=s[i-1].f.f; //lara plays
        else sb+=s[i-1].f.s; // Jonah plays 
    }
    //cout<<sa<<" "<<sb<<endl;
    if(sa>sb)cout<<"First\n";
    else if(sa<sb) cout<<"Second\n";
    else cout<<"Tie\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
