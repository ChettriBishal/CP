#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll nCr(int n,int k)
{
    ll res = 1;
    k = min(k,n-k);

    for(int i=1;i<=k;i++){
        res *= (n-i+1);
        res /= i;
    }

    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<nCr(n-1,k-1)<<endl;
    }

    return 0;
}
