#include<bits/stdc++.h> //bis
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int>a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        a.push_back(d);
    }
    vector<int>x,y,z;
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
            x.push_back(i+1); //consider index to start from 1 for counting
        else if(a[i]==2)
            y.push_back(i+1);
        else 
            z.push_back(i+1);
    }
    int t=min(x.size(),y.size());
    int r=min(t,(int)z.size()); //minimum size will give the number of teams possible
    if(r<1){
        cout<<0<<endl;
        return 0;
    }
    cout<<r<<endl;
    for(int i=0;i<r;i++)
        cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<"\n";
    return 0;
}

