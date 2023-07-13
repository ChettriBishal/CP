#pragma GCC optimize("O2")

#include<bits/stdc++.h>
#ifdef Bis
#include"bistimulus.h"
#else
#define debug(...) 303
#endif


using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    sort(a.begin(),a.end());
    
    while(q--){
        int x;
        cin>>x;
        int ind=lower_bound(a.begin(),a.end(),x)-a.begin();
        if(ind>n-1){
            cout<<"POSITIVE\n";
            continue;
        }
        if(a[ind]==x){
            cout<<0<<"\n";
            continue;
        }
        ind=n-ind; // elements greater than x 
        // if x< a[i] then (x-a[i]) is negative 
        // if the count of negative is even then product becomes positive
        // if odd then product remains negative
        if(ind&1){ // odd count
            cout<<"NEGATIVE\n";
        }
        else{ // even count
            cout<<"POSITIVE\n";
        }
    }


    return 0;
}
// https://www.codechef.com/COOK130B/problems/WAV2
