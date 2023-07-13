#include<bits/stdc++.h>
using namespace std;

set<vector<int>> bis;

void sum_it_up(vector<int>& a, vector<int> out, int i, int T, int n)
{
    if(T == 0){
        if(bis.find(out) == bis.end())
            bis.insert(out);
        return;
    }
    if(i>= n) 
        return;
    
    // including the current value
    if(a[i]<=T){
        out.push_back(a[i]);
        sum_it_up(a,out,i+1,T-a[i],n);
        out.pop_back();
    }
    // excluding the current value
    sum_it_up(a,out,i+1,T,n);

}

int main()
{
#ifdef Bis

    freopen("test.txt","r",stdin);
#endif
    int n, T;
    cin>>n;
    
    vector<int> a(n), out;
    for(int &x: a ) cin>>x;

    sort(a.begin(),a.end());
    cin>>T;
    
    sum_it_up(a,out,0,T,n);
    
    for(auto k: bis){
        for( auto i: k )
            cout<<i<<" ";
        cout<<endl;
    }

    return 0;
    
}
