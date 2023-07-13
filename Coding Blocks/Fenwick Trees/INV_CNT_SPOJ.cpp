/*
 * Wed Aug 11 19:58:48 2021
 *  https://www.spoj.com/problems/INVCNT/
 *Let A[0...n - 1] be an array of n distinct positive integers.
 If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A. 
 Given n and an array A your task is to find the number of inversions of A.
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e7+3;

long long  BIT[N]; // take this as long long 

void update(int i,int inc,int n)
{
    while(i<=n){
        BIT[i] += inc;
        i += (i & (-i));
    }
}

int query(int i)
{
    int sum = 0;
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

    memset(BIT,0,sizeof(BIT)); 
    for(int i= 1;i<=n;i++) cin>>a[i];
    
    int maxval = *max_element(a,a+n+1); // the maximum value in the array will act as the upper bound
    for(int i = n;i >=1;i--){
        cnt += query(a[i]-1);
        update(a[i],+1,maxval); // a[i] is itself acting as an index
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
