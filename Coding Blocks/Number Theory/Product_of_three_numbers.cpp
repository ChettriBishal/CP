#include<bits/stdc++.h>
#define f first 
#define s second
#define pb push_back
#define int long long 
using namespace std;
const int N=1000000;
bitset<N+3> b;
void sieve()
{
    b.set();
    b[1]=b[0]=0;
    for(int i=4;i<=N;i+=2)
        b[i]=0;
    for(int i=3;i*i<=N;i+=2)
    {
        if(b[i]){
            for(int j=i*i;j<=N;j+=i)
                b[j]=0;
        }
    }
}
int epow(int a,int b)
{
    int res=1;
    while(b){
        if(b&1)
            res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;

}
void solve()
{
    int num;
    cin>>num;
    int n=num;
    vector<pair<int,int>>res;
    for(int i=2;i*i<=n;i++)
    {
        if(b[i]){
            int p=0;
            if(n%i==0){
                while(n%i==0){
                    n=n/i;
                    p++;
                }
                res.push_back({i,p});
            }
        }
    }
    // if still not factorised
    if(n!=1){
        res.push_back({n,1});
    }
    if(res.empty()){
        cout<<"NO\n";
        return;
    }
    sort(res.begin(),res.end());
    if(res.size()>=3){
        cout<<"YES\n";
        int i=0,val=1;
        vector<int>fin;
        for(i=0;i<(int)res.size();i++){
            if(i<(int)res.size()-2)
                val*=epow(res[i].f,res[i].s);
            else
                fin.pb(epow(res[i].f,res[i].s));
        }
        fin.pb(val);
        sort(fin.begin(),fin.end());
        for(auto k:fin)
            cout<<k<<" ";
        cout<<endl;
        return ;
    }
    // if the size is one
    if(res.size()==1){
        int k=res[0].second;
        if(k<6){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            int base=res[0].f;
            int up=res[0].s; // power of the prime factor
            for(int i=1;i<=2;i++){ // first two
                cout<<epow(base,i)<<" ";
            }
            cout<<epow(base,up-3);
            cout<<endl;
        }
        return;
    }
    // last case only two prime factors
    int val=num/(res[0].f * res[1].f);
    if(val !=1 and val !=res[0].f and val!=res[1].f){
        cout<<"YES\n";
        vector<int>fin;
        fin.pb(val);
        for(auto k:res)
            fin.pb(k.f);
        sort(fin.begin(),fin.end());
        for(auto k:fin)
            cout<<k<<" ";
        cout<<endl;
    }
    else 
        cout<<"NO\n";
    return;
}
int32_t main()
{
    sieve();
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
#ifdef bistimulus
    freopen("input.txt","r",stdin);
#endif
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
// https://codeforces.com/contest/1294/problem/C
