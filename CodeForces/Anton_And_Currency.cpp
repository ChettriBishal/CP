#include<bits/stdc++.h>
#ifdef M3sh
#include"bistimulus.h"
#else
#define debug(...) 303
#endif
using namespace std;
#define f first
#define s second
int main()
{
    string op;
    cin>>op;
    string s=op;
    int n=(int)s.length();
    int last=s[n-1]-'0';
    bool en=false;
    for(int i=n-2;i>=0;i--){
        int num=s[i]-'0';
        if(num%2==0 && num>last){
            swap(s[i],s[n-1]);
            en=true;
            break;
        }
    }
    string val1="-1",val2="-1";
    if(en){
        val1=s;
        s=op;
        en=false;
    }
    for(int i=0;i<n-1;i++){
        int num=s[i]-'0';
        if(num%2==0 && num<last){
            swap(s[i],s[n-1]);
            en=true;
            break;
        }
    }
    if(en){
        val2=s;
    }
    if(val1=="-1" && val2=="-1"){
        cout<<-1<<endl;
    }
    else{
        if(val1>val2) cout<<val1<<endl;
        else cout<<val2<<endl;
    }
    debug(val1);
    debug(val2);
    return 0;

}
// https://codeforces.com/blog/entry/16048?locale=en
