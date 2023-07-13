/*
The Fibonacci sequence is defined by the following relation:

F(0) = 0
F(1) = 1
F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M, you have to calculate the sum (F(N) + F(N + 1) + … + F(M)) mod 1000000007.
*/
#include<iostream>
#include<vector>
using namespace std;
const int M = 3;
const long MOD = 1000000007;
typedef long long ll;
class matrix{
    public:
        ll data[M][M];
        matrix(){
            for(int  i=1;i<M;i++)
                for(int j=1;j<M;j++)
                    data[i][j] = 0;
        }
        matrix operator * (const matrix & temp)const{
            matrix res = matrix();
            for(int i =1;i<M;i++){
                for(int j =1;j<M;j++){
                    for(int k=1;k<M;k++){
                        res.data[i][j] = (res.data[i][j] + (data[i][k] * temp.data[k][j])) % MOD;
                    }
                }
            }
            return res;
        }

        matrix pow(int n)
        {
            if( n == 1 ){
                return *this;
            }
            if( n &1 ){
                return *this * pow(n-1);
            }
            matrix half = pow(n>>1);
            
            return  half*half;
        }
};

ll getNthterm(ll n)
{
    if(n == 0){
        return 0;
    }

    if( n== 1 ){
        return 1;
    }
    
    matrix F1, T;
    F1.data[1][1] = 1;
    F1.data[2][1] = 1;
    T.data[1][1] = 0, T.data[1][2] = 1;
    T.data[2][1] = 1, T.data[2][2] = 1;

    matrix res = T.pow(n-1) * F1; // the order in which you multiply is also important

    return res.data[1][1];

}
// 0 1 1 2 3 5 8 ... --->terms
// 0 1 2 3 4 5 6 ... --->i


/* Sum(n) = F(n+2) - F(1)
 Sum(n) = F(n+2) - 1
 Sum[ n, m ] = Sum(m) - Sum(n-1)
             = F(m+2) -1 -(F(n-1+2) - 1)
             = F(m+2) - F(n+1)
*/
void solve()
{
    int n,m;
    cin>>n>>m;
   
    ll sum =(getNthterm(m+2) - getNthterm(n+1) + MOD) % MOD;

    cout<<sum<<endl;
}

int main()
{

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}


