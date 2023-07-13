#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string>drinks{"ABSINTH","BEER","BRANDY","CHAMPAGNE","TEQUILA","GIN","RUM","SAKE","VODKA","WHISKEY","WINE"};
    int n;
    cin>>n;
    int cnt=0;
    string g;
    for(int i=0;i<n;i++){   
        cin>>g;
        if(isdigit(g[0])){
            if(stoi(g)<18) cnt++;
        }
        else{
            for(auto k:drinks){ 
                if(k==g){
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
