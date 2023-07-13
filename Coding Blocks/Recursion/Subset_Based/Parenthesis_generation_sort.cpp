/*
 * To generate parenthesis for N pairs 
 * Then sort all the generated parenthesis
 * '(' has higher value than ')'
 *
 */

#include<bits/stdc++.h>
using namespace std;
vector<string> arr;

bool comp(string a, string b)
{
    for(int i=0;i<(int)a.length();i++){
        if(a[i]==b[i])
            continue;
        if(a[i]==')' && b[i]=='(')
            return true;
        else
            return false;
    }
    return false;
}
void parenthesis(char* s, int n, int i, int opening, int closing)
{
    if(i==2*n){
        s[i]='\0';
        arr.push_back(s);
        return;
    }
    if(opening<n){
        s[i]='(';
        parenthesis(s,n,i+1,opening+1,closing);
    }
    if(closing<opening){
        s[i]=')';
        parenthesis(s,n,i+1,opening,closing+1);
    }
}
int main()
{
    int n;
    cin>>n;
    char res[100];
    parenthesis(res,n,0,0,0);
    
    sort(arr.begin(),arr.end(),comp);
    
    for(auto k: arr)
        cout<<k<<endl;

    return 0;
}
