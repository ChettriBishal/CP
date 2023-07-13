#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector< vector <ll> > matrix; 
const ll MOD = 1e9+7;
const int K = 2;

matrix mul(matrix A, matrix B)
{
    matrix C(K+1,vector<ll>(K+1));

    for(int i=0;i<K;i++)
        for(int j=0;j<K;j++) 
            for(int t=0;t<K;t++)
                C[i][j]=(C[i][j] + A[i][t]*B[t][j])  %  MOD;
    
    return C;
}

// To find A^p
matrix pow(matrix A, ll p)
{
    if(p==1)
        return A;
    if(p &1)
        return mul(A,pow(A,p-1));

    matrix res = pow(A,p/2);

    return mul(res,res) ; }



int main()
{
   matrix F1(K,vector<ll>(K));

    // consider 1, 1, 2, 3, 5, .....

    // First 2 terms = 1, 1

   F1[0][0]=1; F1[1][0]=1;

   int t;
   cin>>t;
   while(t--){
       matrix T(K,vector<ll>(K+1));
       for(int i=0;i<K;i++)
           for(int j=0;j<K;j++)
               T[i][j]=1;
       T[0][0]=0;
        
       ll n;
       cin>>n;

       if(n==1){
           cout<<1<<endl;
           continue;
       }
        // Considering 1 1 2 3 5..... 

       T=pow(T,n-1); 
       T=mul(T,F1);
       cout<<T[0][0]<<endl;
   }

   return 0;
}
