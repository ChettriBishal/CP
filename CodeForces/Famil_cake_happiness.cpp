#include<bits/stdc++.h> // nCr
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> rows(n,0),cols(n,0); // to store the cnt

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            if(ch == 'C'){
             rows[i]++;
             cols[j]++;
            }
        }
    }
    int res =0;
    for(int k: rows){
        if(k >=2){
            res += k* (k-1)/2;  // nC2
        }
    }
    for(int k: cols){
        if(k >=2){
            res += k*(k-1)/2;  // nC2
        }
    }

    cout<<res<<endl;

    return 0;

}
