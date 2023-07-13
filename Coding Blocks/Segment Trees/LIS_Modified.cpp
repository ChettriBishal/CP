/*
 *You are given a sequence of N integers A denoted by A[1] , A[2]…..A[N].
 *Each integer in the sequence has a value associated with it W[1],W[2]…. W[N].
 *You have to select a subsequence of given array A such that all the elements in A are in strictly increasing order and sum of values of elements in this selected subsequence is maximum. You have to print this maximum value.
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

ll a[N],b[N],c[N];

// segment tree to store the maximum subsequence sum possible with respect to current a[i]  
class segment_tree{
    public:
        ll tree[4*N+3];

        // ss , se --> tree range indices
        // i -> index of array to be updated
        // idx -> index of current the tree node
        void update(int ss,int se,ll i,ll val,int idx)
        {
            if(i> se || i<ss){
                return;
            }

            if(ss == se){
                tree[idx] = max(val,tree[idx]);
                return;
            }

            int mid = (ss + se)/2;
            update(ss,mid,i,val,2*idx+1);
            update(mid+1,se,i,val,2*idx+2);
            tree[idx] = max(tree[2*idx+1],tree[2*idx+2]);
        }
        
        // ss, se --> tree range indices
        // qs, qe --> query range indices
        // idx -->index of the current tree node
        ll query(int ss,int se,ll qs,ll qe,int idx)
        {
            if(qs > se || qe <ss){
                return 0;
            }

            if(qs <= ss && qe >= se) 
            {
                return tree[idx]; 
            }
            
            int mid = (ss + se)/2;
            ll left = query(ss, mid,qs,qe,2*idx+1);
            ll right = query(mid+1,se,qs,qe,2*idx+2);
           
            return max(right,left);
        }            
        
        void clear(){
            memset(tree,0,sizeof(tree));
        }
}bis;


void solve()
{
    int n; cin>>n;

    for(int i= 0 ;i<n;i++) {
        cin>>a[i]; 
        b[i] = a[i];
    }
    sort(b,b+n);

    // coordinate compression
    for(int i= 0 ;i<n;i++){
        a[i] = lower_bound(b,b+n,a[i])-b +1;
    }
    
    // weight array
    for(int i = 0;i<n;i++){
        cin>>c[i];
    }
    
    ll res = 0;
    for(int i= 0;i<n;i++){
       ll val = c[i];
       val += bis.query(0,n-1,0,a[i]-1ll,0);
       bis.update(0,n-1,a[i],val,0);
       res = max(res,val);
    }
    cout<<res<<endl;
    bis.clear();
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
