#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=-1,r=-1;
    bool en=true; // only L 
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            en=false;
            break;
        }
    }
    if(en){
        r=s.find('L'); // left of all footprints
        l=r+1;
    }
    else{
        bool ne=true;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                ne=false;
                break;
            }    
        }
        if(ne){
            for(int i=n-1;i>=0;i--){
                if(s[i]=='R'){
                    r=i+2;
                    break;
                }
            }
            l=(r-1);
        }
        else{
            for(int i=n-1;i>0;i--){
                if(s[i]==s[i-1] and s[i]=='R'){
                    l=i;
                    r=i+1;
                    break;
                }
            } 
            if(l==-1){
                for(int i=n-1;i>=0;i--){
                    if(s[i]=='L' and s[i-1]=='R'){
                        l=i+1;
                        r=i;
                    }
                }    
            }
        }
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}
