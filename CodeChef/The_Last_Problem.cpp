#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
const int N=1005;
vector<vi> mat(N,vi(N,0));
void matrix() // create the matrix required
{
    for(int i=1;i<=1000;i++){
        mat[i][1]=i*(i+1)/2; 
        for(int j=2;j<=1000;j++){
            mat[i][j]=mat[i][j-1]+(i-1)+(j-1);
        }
    }	
}
void solve()
{
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int sum=0;
    // first traverse the row
    for(int i=x1;i<=x2;i++){
        sum+=mat[i][y1];
    }
    // then traverse the column
    for(int i=y1+1;i<=y2;i++){
        sum+=mat[x2][i];
    }
    cout<<sum<<endl;
}
signed main()
{
	#ifdef bistimulus
		freopen("input.txt","r",stdin);
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
    io;
    int t;
    matrix();
    cin>>t;
    while(t--)
        solve();
	#ifdef bistimulus
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr <<endl<< "Time Elapsed: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
    return 0;
}

