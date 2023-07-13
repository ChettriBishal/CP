/*
 * https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/equal-elements-2-db70c1ae/
 * 11-Apr-21 1:50:31 PM
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    int odd=0;// number of odd numbers
    for(ll &x:a){
        cin>>x;
        if(x&1) odd++; 
    }
    cout<<min(odd,n-odd)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
