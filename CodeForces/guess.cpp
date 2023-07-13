/*
 * Bishal 
11-Apr-21 1:06:39 AM
 */
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    ll low=2*(-1e9),high=2*(1e9);
    while(n--)
    {
        ll d;
        char y;
        string g;
        cin>>g>>d>>y;
        if(y=='N'){
            if(g=="<") g=">=";
            else if(g==">") g="<=";
            else if(g==">=") g="<";
            else g=">";
        }
        if(g=="<") high=min(high,d-1);
        else if(g=="<=") high=min(high,d);
        else if(g==">=") low=max(low,d);
        else low=max(low,d+1);
    }
    if(low>high) cout<<"Impossible\n";
    else cout<<low<<endl;
    return 0;
}
