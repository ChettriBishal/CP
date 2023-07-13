#include<iostream>
#include<cassert>
using namespace std;
typedef long long ll;
const int MAX=18;
int MOD;
class matrix{
    public:
    int rows=MAX-1;
    int cols=MAX-1;
    ll data[MAX][MAX];

    matrix(){
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=cols;j++)
                data[i][j]=0;
        }
    }
  
    // overloading * operator to multiply two matrices
    // The first matrix calls the operator function and second matrix is passed as argument to the function
    // The first matrix acts as an object that invokes the function while the second matrix is passed 
    // here data[][] symbolizes the first matrix while mat[][] -->second matrix
  
  
    matrix operator * (const matrix & temp)const{
        assert(cols==temp.rows);
        matrix res=matrix(); // invoking the constructor
        for(int i=1;i<=rows;i++){
            for(int j=1;j<=temp.cols;j++)
                for(int k=1;k<=cols;k++)
                    res.data[i][j]=(res.data[i][j]+ data[i][k]* temp.data[k][j]%MOD)%MOD;
        }
        res.rows=rows;
        res.cols=temp.cols;
        return res;
    }
    matrix pow(ll e){
        if(e==1)
            return *this;
        if(e & 1)
            return (*this) *pow(e-1);
        matrix half= pow(e>>1);
        return half*half;
    }
};

ll NthSum(matrix T,matrix F1, ll N)
{
    if(N<=F1.rows-1)
    {
        ll res=0ll;
        for(int i=1;i<=N;i++)
            res=(res+F1.data[F1.rows+1-i][1])%MOD;
        return res;
    }
    matrix res = T.pow(N)*F1; // gets F(N+1) which has the sum of the Nth elements 
    return (res.data[1][1]+MOD)%MOD;

}
int main()
{
    int t,k;
    ll b[MAX],c[MAX];
    ll M,N;
    cin>>t;
    while(t--){
        cin>>k;
        for(int i=1;i<=k;i++)
            cin>>b[i];
        for(int i=1;i<=k;i++)
            cin>>c[i];
        cin>>M>>N>>MOD;
        if(N<=k){
            ll res=0;
            for(int i=(int)M;i<=(int)N;i++)
                res=(res+b[i])%MOD;
            cout<<res<<"\n";
            continue;
        }
        matrix T, F1;
        T.rows=T.cols=k+1;
        T.data[1][1]=1; 
        
        for(int i=2;i<=k+1;i++)
            T.data[i-1][i]=1;
        
        for(int i=1;i<=k;i++) // k+1 th row
            T.data[1+k][i+1]=c[k+1-i];
       
        F1.rows=k+1;
        F1.cols=1;
        F1.data[1][1]=0; // initial sum
        for(int i=1;i<=k;i++)
            F1.data[i+1][1]=b[i];
        
        ll start = NthSum(T,F1,M-1);
        ll end = NthSum(T,F1,N);
        cout<<(end-start+MOD)%MOD<<"\n";
    
    }

    return 0;

}
/*
 * F_2 contains the sum of the first two terms of the recurrence 
 * Thus F_N+1 contains the sum of the first N terms of the recurrence
 * https://www.spoj.com/problems/SPP/
*/
