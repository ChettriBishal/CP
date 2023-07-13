#include<bits/stdc++.h> //bis
using namespace std;
int main()
{
    char st[101];
    cin>>st;
    int n=strlen(st);
    int b[51],i;
    string r="";
    for(i=0;i<n;i=i+2)
        r.push_back(st[i]);
    n=r.length();
    for(i=0;i<n;i++) // converting to int values
        b[i]=r[i]-'0';
    sort(b,b+n);
    for(i=0;i<n;i++){
        if(i!=n-1)
            cout<<b[i]<<"+";
        else 
            cout<<b[i];
    }
    return 0;
}
