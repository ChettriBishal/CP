#include<bits/stdc++.h>
using namespace std;
int main()
{   
    string a,b;
    getline(cin,a);
    getline(cin,b);
    map<char,int>freq_a,freq_b;
    for(auto k:b) // frequencies of each character from b
        freq_b[k]++;
    int resl=-1,resr=1e9;
    int l=0; // left pointer
    for(int r=0;r<(int)a.size();r++) // see difference between count and access
    {
        freq_a[a[r]]++;
        bool ok=true;
        for(auto k:freq_b){ // checking if all letters are present in the window or present less 
            if(freq_a.count(k.first)==0 or freq_a[k.first]<k.second){
                ok=false;
                break;
            }    
        }
        if(!ok) continue;
        while(l<(int)a.size() && l<=r && (freq_b.count(a[l])==0 or freq_a[a[l]] >freq_b[a[l]]))
        {
            freq_a[a[l]]--; // decreasing it's count from the window
            if(freq_a[a[l]]==0) // if that value isn't required at all then remove it from window
                freq_a.erase(a[l]);
            l++;
        }
        /* cout<<l<<" "<<r<<endl; */
        if(r-l+1<resr-resl+1){ // check if the gap is less than the previous 
            resr=r;
            resl=l;
        }
    }
    if(resl==-1){
        cout<<"No String\n";
    }
    else
        cout<<a.substr(resl,resr-resl+1)<<"\n"; // segment of shortest gap starting from resl
    return 0;

}
/*
The count function checks if that particular key exists or not 
whereas freq[x]==0 checks if for the key x present in the hash table the value is zero for that key or not
*/
