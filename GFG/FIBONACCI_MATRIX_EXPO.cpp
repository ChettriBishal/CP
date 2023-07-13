#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 3;
const long MOD = 1e9+7; 
class matrix{
    public:
        ll data[MAXN][MAXN];
        matrix(){
            for(int i= 1;i<MAXN;i++){
                for(int j=1;j<MAXN;j++)
                    data[i][j] = 0;
            }
        }
        matrix operator * (const matrix & A)const{

            matrix C = matrix(); // to store the resultant 
            for(int i =1;i<MAXN;i++)
                for(int j=1;j<MAXN;j++)
                    for(int k=1;k<MAXN;k++)
                        C.data[i][j] = (C.data[i][j] + data[i][k] * A.data[k][j]) % MOD;

            return C;

        }

        matrix pow(ll n)
        {
            if( n== 1)
                return *this;
            if(n &1)
                return *this * pow(n-1);
            matrix half = pow(n>>1);
            return half* half;
        }
};

int FindNthTerm(long long int n) {

        if( n== 1 ){
            return 1;
        }
        
        matrix F1;
        F1.data[1][1] = 1; // as 1st term = 1 (A.T.Q)
        F1.data[2][1] = 2; // as 2nd term = 2 (A.T.Q)
        
        matrix T; // transformation matrix
        T.data[1][1]= 0, T.data[1][2] = 1;
        T.data[2][1] =1; T.data[2][2] = 1;
       
        matrix res = T.pow(n-1)* F1;
        
        return res.data[1][1];
}

int main()
{
    cout<<"Enter the value of n:\n";
    int n;
    cin>>n;
    cout<<FindNthTerm(n)<<endl;

    return 0;
}

