#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    vector<ll>a(n);
    for(ll &x:a) cin>>x;
    int l=-1,r=-1;
    for(int i=0;i<n-1;i++)
        if(a[i]>a[i+1]){
            l=i;
            break;
        }
    for(int i=n-1;i>=1;i--)
        if(a[i]<a[i-1]){
            r=i;
            break;
        }
    bool en=true;
    if(l==-1 && r==-1) // already sorted 
        l=r=0;
    else{
        int i=l,j=r;
        while(i<=j)
            swap(a[i++],a[j--]);
        for(int i=0;i<n-1;i++) // checking after swapping
            if(a[i]>a[i+1]){
                en=false;
                break;
            }
    }
    if(en){
        cout<<"yes\n";
        cout<<l+1<<" "<<r+1<<"\n";
    }
    else
        cout<<"no\n";
    return 0;

}
