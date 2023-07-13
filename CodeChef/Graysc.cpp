#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define PI 3.141592653589793238
#define f first
#define s second
#ifdef bistimulus
#define focus(b) cerr<< (#b)<<" = ";cerr<<b;cerr<<endl;
#else
#define focus(b);
#endif
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i,g,n) for(ll i=g;i<n;i++)
bool solve()
{
   int n;
   cin>>n;
   vector<ull>a(n);
   for(ull &x:a){
       cin>>x;
   }
   if(n>=130)  
    return true;
   rep(i,0,n){
        rep(j,i+1,n){
            rep(k,j+1,n){
                ull val=(a[i]^a[j]^a[k]);
                vector<ull>::iterator check =find(a.begin()+k+1,a.end(),val); // take care of the range...it must check if it's present above index k
                if(check!=a.end())
                    return true;
            }
        }

   }
   return false;
}
signed main()
{
    io;
    int t=1;
	#ifdef bistimulus
		freopen("input.txt","r",stdin);
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
    while(t--)
        solve()?cout<<"Yes\n":cout<<"No\n";
	#ifdef bistimulus
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr <<endl<< "Time Elapsed: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
    return 0;
}

