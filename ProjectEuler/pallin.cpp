#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool pal(ll at)
{
   ll rev=0,org;
   long k;
   org=at;
   while(at!=0)
   {
       k=at%10;
       rev=rev*10+k;
       at/=10;
   }
   if(rev==org) return true;
   else return false;
}
int main()
{
    ll i,yes=0;
    for(i=999;i>=100;i--)
    {
        for(int j=999;j>=i;j--)
        {
            if(i*j<=yes) break;
            if(pal(i*j)) yes=i*j;
        }
    }
    cout<<yes<<endl;
    return 0;
}
/*
#include<iostream>
#define ll long long
using namespace std;
bool pal(ll at)
{
   ll rev=0,org;
   long k;
   org=at;
   while(at!=0)
   {
       k=at%10;
       rev=rev*10+k;
       at/=10;
   }
   if(rev==org) return true;
   else return false;
}
int main()
{
    ll i,yes=0,j;
    int dif=0;
    for(i=999;i>=100;i--)
    {
        if(i%11==0){
            j=999;
            dif=1;
        }
        else{
            j=990;
            dif=11;
        }
        for(;j>=i;j=j-dif){
            if(i*j<yes) break;
            if(pal(i*j)) yes=i*j;
        }
    }
    cout<<yes<<endl;
}
*/
