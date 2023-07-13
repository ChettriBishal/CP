#include<bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> x,y;
    int w,h,n;
    cin>>w>>h>>n;
    x.resize(n+3);
    y.resize(n+3);
    x[0] = 0;
    y[0] = 0;

    for(int i= 1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    x[n+1] = w +1; // the end points we don't need to subtract extra one so we add here
    y[n+1] = h +1;

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    int dx =0, dy =0;
    for(int i= 0;i<n+2;i++){
        dx = max(dx,x[i+1]-x[i]-1);
        dy = max(dy,y[i+1]-y[i]-1);
    }
    
    cout<<dx * dy<<endl;

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
