#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int arr[N];
vector<int> tree[2*N+4]; // [] brackets enables you to have vector within the individual cell


void build(int s,int e,int index)
{
    if(s == e){
        tree[index]=vector<int>(1,arr[s]);
        return ;
    }
    int mid = (s+e)/2;
    build(s,mid,2*index);
    build(mid+1,e,2*index+1);
    merge(tree[2*index].begin(),tree[2*index].end(),tree[2*index+1].begin(),tree[2*index+1].end(),back_inserter(tree[index]));
}

int query(int s,int e,int qs,int qe,int ind,int k)
{
    // no overlap
    if(s>qe || e< qs)
        return 0;
  
    // complete overlap
    if(qs <= s && qe >= e){
        vector<int>::iterator pos = lower_bound(tree[ind].begin(),tree[ind].end(),k);
        if(pos!=tree[ind].end())
            return (int) (tree[ind].end()- pos);
        return 0;
    }

    int mid = (s+e)/2;
    int left = query(s,mid,qs,qe,2*ind,k);
    int right = query(mid+1,e,qs,qe,2*ind+1,k);
    
    return (left+ right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef Bis 
    freopen("test.txt","r",stdin);
#endif

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    build(0,n-1,1);
    int q;
    cin>>q;

    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<query(0,n-1,l-1,r-1,1,k)<<endl;
    }

    return 0;

}
// https://www.geeksforgeeks.org/merge-sort-tree-smaller-or-equal-elements-in-given-row-range/
