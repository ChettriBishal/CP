#include<iostream>
#include<set>
using namespace std;
class bbb{
    public:
        multiset<int> val;
        bbb(string s){
            for(auto k: s){
                val.insert(k-'0');
            } 
        }
};
void solve()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        bbb check(s);
        cnt+=(check.val.count(1));
    }
    // odd number of 1's implies that xor is 1
    if(cnt &1) cout<<"YES\n";
    else cout<<"NO\n";

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
//https://www.codechef.com/problems/XORFOLD
