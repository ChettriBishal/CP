#include<iostream>
#include<vector>
using namespace std;

void build(vector<int>& arr,vector<int>& pre)
{
    pre[0] = arr[0];
    for(int i=1;i<arr.size();i++)
        pre[i] = pre[i-1] + arr[i];
}

int query(vector<int>& pre, int l,int r)
{
    if( l == 0 )
        return pre[r];

    return  pre[r] - pre[l-1];   
}

int main()
{
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    vector<int> pre , arr;
    int n;
    cin>>n;
    arr.resize(n,0);
    pre.resize(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        cout<<arr[i]<< " ";
    cout<<endl;
    
    build(arr,pre);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        printf("%d %d --> ",l,r);
        cout<<query(pre,l,r)<<endl;
    }
    return 0;
}
