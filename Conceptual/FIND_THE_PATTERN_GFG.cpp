/* Find the pattern GFG
Given a sequence as follow:
1,1,7,19,73....
Find the Nth term of the given sequence.
*/
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

const int MAXN = 3;
const long MOD = 1e9+7;
typedef long long ll;
class matrix{
    public:
    ll data[MAXN][MAXN];
    matrix(){
        for(int i=1;i<MAXN;i++)
            for(int j=1;j<MAXN;j++)
                data[i][j] = 0;
    }

    matrix operator* (matrix const& B) const{
    
        matrix res = matrix();
        for(int i=1;i<MAXN;i++)
            for(int j=1;j<MAXN;j++)
                for(int k=1;k<MAXN;k++)
                    res.data[i][j] = (res.data[i][j] + data[i][k]*B.data[k][j] ) % MOD;

        return res;

    }
    
    matrix pow(ll n){
        if( n== 1 )
            return *this;
        
        if(n &1)
            return *this * pow(n-1);

        matrix half = pow(n>>1);
        return half * half;
    }
};

int getNthterm(int N)
{
    if( N <=2 ){
        return 1;
    }

    matrix F1;
    F1.data[1][1] = 1;
    F1.data[2][1] = 1;

    // Now creating the transformation matrix
    matrix T; 
    T.data[1][1] = 0, T.data[1][2] = 1;
    T.data[2][1] = 5, T.data[2][2] = 2;
    
    matrix res= T.pow(N-1)* F1;

    return res.data[1][1];

}


int main()
{
    int n;
    cin>>n;
        
    cout<<getNthterm(n)<<endl;

    return 0;
}
