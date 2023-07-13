#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main()
{
    int n;
    cin>>n;
    vector<ll>a(n);
    for(ll &x:a) cin>>x;
    set<ll>st;
    ll res=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j<n && st.find(a[j])==st.end()){
            st.insert(a[j++]); // add current element to the window
        }
        ll cnt=j-i;
        res+=(((cnt%mod)+mod)%mod)*(((cnt+1)%mod+mod)%mod)/2;
        st.erase(a[i]); // remove current element from the window
    }
    cout<<res%mod<<"\n";
    return 0;


}
