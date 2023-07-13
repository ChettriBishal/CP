#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long MOD=1e9;
const int MAX=18;
class matrix{
    public:
    int rows=MAX-1,cols=MAX-1;
    ll data[MAX][MAX];
    matrix(){
       for(int i=1;i<=rows;i++)
           for(int j=1;j<=cols;j++)
               data[i][j]=0;
    }
    // overloading this operator
    matrix operator * (matrix const & temp)const{
        assert(cols==temp.rows);
        matrix res=matrix();
        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=temp.cols;j++){
                for(int k=1;k<=cols;k++)
                    res.data[i][j]=(res.data[i][j]+ (data[i][k]* temp.data[k][j])%MOD)%MOD;
            }
        }
        res.rows=rows;
        res.cols=temp.cols;
        return res;
        
    }
    matrix pow(ll b){
        if(b==1)
            return *this;
        if(b&1)
            return (*this)*pow(b-1);
        matrix half=pow(b>>1);
        return half*half;
    }
};

void solve()
{   
    vector<ll>b,c;
    int k;
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
    if(n<=k){
        cout<<b[n-1]<<"\n";
        return;
    }
    
    matrix T,F1;
    T.rows=T.cols=k;
    for(int i=1;i<k;i++) // all except the last row
        T.data[i][i+1]=1;
    for(int i=1;i<=k;i++)
        T.data[k][i]=c[k-i];
    
    F1.rows=k;
    F1.cols=1;
    for(int i=1;i<=k;i++) 
        F1.data[i][1]=b[i-1];
    matrix res=T.pow(n-1)*F1;
    b.clear();
    c.clear();
    cout<<res.data[1][1]<<"\n";

}
int main()
{
#ifdef bistimulus
    freopen("input.txt","r",stdin);
#endif
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;

}
