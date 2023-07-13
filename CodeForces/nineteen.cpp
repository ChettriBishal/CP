#include<bits/stdc++.h>
using namespace std;
bool isthere(string& s,char a){ // checks if character is present in the string
    int p=s.find(a);
    if(p<s.length()){ // if present then we change that so that it doesn't affect another round of execution
        s[p]='*';
        return true;
    }
    else return false;
}
int main()
{
    string s,res="";
    cin>>s;
    int n=(int)s.length();
    for(int i=0;i<n;i++)
    {
        if(isthere(s,'n')) res+='n';
        else break;
        if(isthere(s,'i')) res+='i';
        else break;
        if(isthere(s,'n')) res+='n';
        else break;
        if(isthere(s,'e')) res+='e';
        else break;
        if(isthere(s,'t')) res+='t';
        else break;
        if(isthere(s,'e')) res+='e';
        else break;
        if(isthere(s,'e')) res+='e';
        else break;
    }
    int ans=0;
    while(res.length()>1){
        if(res.substr(0,8)=="nineteen")
            ans++;
        res.erase(0,7);
    }
    cout<<ans<<"\n";
    return 0;

}
