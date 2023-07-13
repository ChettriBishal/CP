#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    vector<int>cnt(26);
    for(char c:s)
        cnt[c-'A']++;
    int ok=0;
    for(int t:cnt){
        ok+=(t%2);    
    }
    if(ok>1){// if more than one unique character 
        cout<<"NO SOLUTION\n";
    }
    else{
        string res="";
        for(int i=0;i<26;i++) // first part of the string
        {
            if(cnt[i]%2==0){
                for(int j=0;j<cnt[i]/2;j++)
                    res+=(i+'A');
            }    
        }
        for(int i=0;i<26;i++) // middle odd number of characters of the string if it's there
        {
            if(cnt[i]&1)
                for(int j=0;j<cnt[i];j++)
                    res+=(i+'A');
        }
        for(int i=25;i>=0;i--) // last part of the string going from back
        {
            if(cnt[i]%2==0){
                for(int j=0;j<cnt[i]/2;j++)
                    res+=(i+'A');
            }    
        }
        cout<<res<<endl;
    }
    return 0;
}
