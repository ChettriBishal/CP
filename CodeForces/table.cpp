#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int t;
    vector<pair<int,int>>a;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>t;
            if(t==1)
                a.push_back({i,j});
        }
    bool en=false;
    for(auto i=a.begin();i!=a.end();i++)
        cout<<(*i).first<<" "<<(*i).second<<endl;
    cout<<"Elements traversal\n";
    for(auto i:a)
        cout<<i.first<<" "<<i.second<<endl;
    cout<<"Using iterators\n";
    for(auto i=a.begin();i!=a.end();i++)
        cout<<i->first<<" "<<i->second<<endl;
  
    for(auto i=a.begin();i!=a.end();i++)
        cout<<(*i).first<<" "<<(*i).second<<endl;
    for(auto i=a.begin();i!=a.end();i++)
    {
        int x=i->first;
        int y=i->second;
        if(x==1 or x==n){ // first or last row
        en=true;
        break;
        }
        if(y==1 or y==m){ // first or last col
        en=true;
        break;
        }
    }
    cout<<endl;
    if(en)
        cout<<2<<endl;
    else
        cout<<4<<endl;
    return 0;

}
