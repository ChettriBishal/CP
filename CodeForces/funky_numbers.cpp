#include<bits/stdc++.h>
using namespace std;
#define N 1e5
typedef long long ll;
int main()
{   
    set<ll>tri_num;  // set of all the triangular numbers till N
    for(int i=1;i<=N;i++){  
        tri_num.insert((ll)i*(i+1)/2);
    }
    ll n;
    cin>>n;
    bool en=false;
    for(auto i=tri_num.begin();i!=tri_num.end();i++)
    {   
        if(n-*i>0 and tri_num.count(n-*i)) // the number should exist in the set
        {   
            en=true;
            break;
        }
    }
    if(en) 
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
