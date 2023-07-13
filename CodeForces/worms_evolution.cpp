#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int &x:a) cin>>x;
    bool en=false;
    int x=0,b=0,c=0;
    for(int i=n-1;i>=0;i--)
    {   
        x=i+1;
        for(int j=0;j<n;j++){   
            for(int k=0;k<n;k++){   
                if(i!=j and j!=k and i!=k and a[j]+a[k]==a[i]){
                    /* cout<<a[j]<<" "<<a[k]<<endl; */
                    b=j+1;
                    c=k+1;
                    en=true;
                    break;
                }
            }
            if(en) break;
        }    
        if(en) break;
    }
    if(en)
        cout<<x<<" "<<b<<" "<<c<<"\n";
    else
        cout<<-1<<"\n";
    return 0;
}
