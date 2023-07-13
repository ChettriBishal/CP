#include<bits/stdc++.h> //bis
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[110],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int>g;
    for(int i=1;i<n-1;i++)
    {
        int diff=-1000;
        for(int j=0;j<n-1;j++)
        {
            if(j+1==i){ 
                if(a[j+2]-a[j]>diff)
                    diff=a[j+2]-a[j];
                j++;
            }
            else{
                if(a[j+1]-a[j]>diff) 
                    diff=a[j+1]-a[j];
            }
        }
        g.push_back(diff);
    }
    cout<<*min_element(g.begin(),g.end());
    return 0;
}