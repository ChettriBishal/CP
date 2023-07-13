#include<bits/stdc++.h>
using namespace std;


void parenthesis(string s, int n, int opening, int closing)
{
    if(s.length()==2*n){
        if(opening==closing){
            cout<<s<<endl;
            return;
        }
        else return;
    }
    
    if(closing<opening){ // ) is lexographically smaller
        parenthesis(s+')',n,opening,closing+1);
    }
    if(opening<n){
        parenthesis(s+'(',n,opening+1,closing);
    }
}

int main()
{
    int n;
    cin>>n;
    string res="";
    parenthesis(res,n,0,0);

    return 0;
}
