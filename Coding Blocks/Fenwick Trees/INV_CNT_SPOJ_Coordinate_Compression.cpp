/* This one using coordinate compresssion
 *Let A[0...n - 1] be an array of n distinct positive integers.
 If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. 
 Given n and an array A your task is to find the number of inversions of A.
 */
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

void update(int i,int inc,int n,long long* BIT)
{
    while(i<=n){
        BIT[i] += inc;
        i += (i & (-i));
    }
}

long long query(int i,long long* BIT)
{
    long long sum = 0;
    while(i > 0){
        sum += BIT[i];
        i -= (i & (-i));
    }
    return sum;
}

void solve()
{
    int n;
    long long cnt = 0;  // take this as long long cause it's gonna be sum of lot of ints
    cin>>n;
    int a[n+1];

    set<int> unq;

    for(int i= 1;i<=n;i++){
        cin>>a[i];
        unq.insert(a[i]);
    }

    map<int,int> hasht;
   
    int ind = 1;
    for(auto k: unq){
        hasht[k] = ind++;
    }
    
    int b[ind+1];
    long long BIT[ind+1]={0};

    for(int i= 1;i<=n;i++){
        b[i] = hasht[a[i]]; // the large values are now mapped to managable values 
    }

    for(int i = n;i >=1;i--){
        cnt += query(b[i]-1,BIT);
        update(b[i],+1,ind,BIT); // a[i] is itself acting as an index
    }
    
    cout<<cnt<<endl;
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
