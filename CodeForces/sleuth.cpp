#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    char t;
    string g;
    while(cin>>g){
        int n=g.length();
        if(isalpha(g[n-1])){ 
            t=tolower(g[n-1]);
        }
        else{
            if(n-2>=0) 
                t=tolower(g[n-2]);
        }
    }
    char vow[]={'a','e','i','o','u','y'};
    bool en=false;
    for(char v:vow){
        if(t==v){
            en=true;
            break;
        }
    }
    if(en)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
