#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
const int MAX=10;
typedef long long ll;

const ll MOD=1e9;

class matrix{
    public:
    int rows=MAX, cols=MAX;
    ll data[MAX][MAX];

    matrix(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++)
                data[i][j]=0;
        }
    }
    matrix operator* ( matrix const& temp ) const{
        assert(cols==temp.rows);
        
        matrix res=matrix();
        for(int i=0;i<rows;i++){
            for(int j=0;j<temp.cols;j++){
                for(int k=0;k<temp.rows;k++){
                    res.data[i][j]=(res.data[i][j]+data[i][k]*temp.data[k][j]) % MOD;
                } 
            }
        }
        res.rows=rows;
        res.cols=temp.cols;
        return res;
    }

    matrix pow(ll n){

        if(n==1)
            return *this;
        if(n&1)
            return (*this) * pow(n-1);
        
        matrix half= pow(n>>1);

        return half*half;
    }
};

void solve()
{
    int k;
    cin>>k;
    vector<ll>b(k),c(k);

    for(int i=0;i<k;i++)
        cin>>b[i];

    for(int i=0;i<k;i++)
        cin>>c[i];

    int n;

    cin>>n;

    if(n<k){
        cout<<b[n-1]<<endl;
        return;
    }

    matrix T, F1;// transformation matrix

    T.rows=T.cols=k;

    for(int i=0;i<k-1;i++){
        T.data[i][i+1]=1;
    }

    for(int i=0;i<k;i++)
        T.data[k-1][i]=c[k-i-1];
    
    F1.rows=k; F1.cols=1;

    for(int i=0;i<k;i++)
        F1.data[i][0]=b[i];

    matrix res= T.pow(n-1) * F1;

    cout<<res.data[0][0]<<endl; 
    
    b.clear();
    c.clear();

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
