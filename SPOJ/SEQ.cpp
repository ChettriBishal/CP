/* Transformation Matrix   */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long  MOD= 1e9;
vector<ll>b,c;
ll k;
vector<vector<ll> > multiply(vector<vector<ll> > A, vector<vector<ll> > B)
{
    vector<vector<ll> > C(k+1,vector<ll>(k+1)); // to store the result
    // logic to multiply matrices 
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            ll res(0);
            for(int e=1;e<=k;e++)
                res=((res+(A[i][e]%MOD*B[e][j]%MOD)%MOD)%MOD);
            C[i][j]=res;
        }
    }
    return C;

}

vector<vector<ll> > pow(vector<vector<ll> >A,ll p)
{
    if(p==1)
        return A;

    // power is odd
    if(p&1)
        return multiply(A,pow(A,p-1));
    // when power is even
    vector<vector<ll> > X=pow(A,p/2);
    return multiply(X,X);

}


ll compute(ll n){
    if(n==0)
        return 0;
    if(n<=k)
        return b[n-1];
    // else we matrix exponentiation
    vector<ll>F1(k+1); // 1 based indexing 
    for(int i=1;i<=k;i++)
        F1[i]=b[i-1];
    // now making transformation matrix
    vector<vector<ll> > T(k+1,vector<ll>(k+1)); // initialising a 2d matrix
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++){
            if(i<k){
                if(j==i+1)
                    T[i][j]=1;
                else
                    T[i][j]=0;
            }
            else{ // kth row
                T[i][j]=c[k-j]; // putting the coefficients in reversed order
            }
            
        }
    // power function 
    T=pow(T,n-1);
    // then multiplication with A vector
    // only the first row and the first column
    ll res=0;
    for(int i=1;i<=k;i++)
        res=(res+(T[1][i]*F1[i])%MOD)%MOD;
    return res;
    
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>k;
        for(int i=0;i<k;i++){
            ll d;
            cin>>d;
            b.push_back(d);
        }
        for(int i=0;i<k;i++){
            ll d;
            cin>>d;
            c.push_back(d);
        }
        ll n;
        cin>>n;
        cout<<compute(n)<<"\n";
        b.clear(); // important to clear for next test case
        c.clear();
    }
    return 0;

}
