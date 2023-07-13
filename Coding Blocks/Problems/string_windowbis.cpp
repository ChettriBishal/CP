#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,b;
    getline(cin,s);
    getline(cin,b);
    map<char,int>frs,frb;
    for(auto k: b)
        frb[k]++;
    int left=0;
    int resl=-1, resr=1e9;
    for(int i=0;i<(int)s.size();i++)
    {
        frs[s[i]]++;
        bool ok=true;
        for(auto k:frb){
            if(frs.count(k.first)==0 or frs[k.first]<k.second){
                ok=false; 
                break;
            }
        }
        if(!ok) continue;
        while(left<(int)s.size() && left<=i && (frb.count(s[left])==0 or frs[s[left]]>frb[s[left]] )){
            frs[s[left]]--;
            if(frs[s[left]]==0) frs.erase(s[left]);
            left++;
            
        }
        if(resr-resl+1>i-left+1){ // minimum gap is required
            resr=i;
            resl=left;
        }
    }
    /* cout<<resl<<" "<<resr<<endl; */
    if(resl==-1){
        cout<<"No String\n";
    }
    else
        cout<<s.substr(resl,resr-resl+1);
    return 0;

}
