#include"bits/stdc++.h"
using namespace std;
int main()
{
    map<char,int>a;
    a['6']=6;
    a['7']=7;
    a['8']=8;
    a['9']=9;
    a['T']=10;
    a['J']=11;
    a['Q']=12;
    a['K']=13;
    a['A']=14;
    char trump;
    cin>>trump;
    a[trump]+=10; // cause it can win any card
    string first,second;
    cin>>first>>second;
    if(first[1]==trump and second[1]!=trump) cout<<"YES\n";
    else if(second[1]==trump and first[1]!=trump) cout<<"NO\n";
    else{
        if(first[1]!=second[1]) cout<<"NO\n";
        else if(a[first[0]]+a[first[1]]>a[second[0]]+a[second[1]]) cout<<"YES\n"; //the sum of suit type and rank 
        else cout<<"NO\n";
    }
    return 0;
}
