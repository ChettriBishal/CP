#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifdef bistimulus
    freopen("input.txt","r",stdin);
#endif
    unordered_map<string,string> res;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        string b,c;
        cin>>b>>c;
        res[b]=c;
    }
    vector<string>prof;
    for(int i=0;i<n;i++){
        string g;
        cin>>g;
        auto it=res.find(g);
        if(it!=res.end()){
            if((g.length()<(*it).second.length()) || g.length()==(*it).second.length()){
                prof.push_back(g);
            }
            else
                prof.push_back(it->second);
            continue;
        }
        prof.push_back(g);
    } 
   for(auto k:prof)
       cout<<k<<" ";
   return 0;
}
