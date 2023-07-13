#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    vector<int>dig;// to store the digits
    while(n){
        int k=n%10;
        dig.push_back(k);
        n/=10;
    }
    //ll res=2*(1<<(dig.size()-1)-1); // sum of N terms of GP
    ll res=(1<<(int)dig.size())-2ll; // res stores the count of numbers less than the given number
    for(int i=0;i<dig.size();i++){
        if(dig[i]==7)
            res+=(1<<i);
    }
    cout<<res+1<<"\n";
    return 0;
}
/*
 * Sum of N terms of GP:
 * a,ar,ar^2,ar^3...
 * Sn= a(r^N -1) / (r-1)
 * in this case a=2
 *  */
