#include<bits/stdc++.h> //bis
using namespace std;
int main()
{
    int n,s,f=0;
    cin>>s>>n;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        if(a[i].first<s)
            s+=a[i].second;
        else{
            cout<<"NO\n";
            f=1;
            break;
        }
    }
    if(f==0)
        cout<<"YES\n";
    return 0;
}