#include<bits/stdc++.h>
using namespace std;


vector<string> generate_graycode(int n)
{

    // base cases
    if( n<= 0 ){ 
        return {"0"};
    }    

    if( n== 1 ){  // 1 bit graycode  
        return {"0","1"};
    }

    // Recursive cases
    vector<string> recur = generate_graycode(n-1);

    vector<string> res;
    // Append 0 to the first half
    for(int i=0;i<recur.size();i++){
        string s = recur[i];
        res.push_back("0" + s);
    }

    // Append 1 to the second half
    for(int i=recur.size()-1;i>=0;i--){
        string s = recur[i];
        res.push_back("1"+s);
    }

    return res;

}

int main()
{
    int n;
    cin>>n;
    vector<string> ans = generate_graycode(n);

    for(auto k: ans){
        cout<<k<<" ";
    }
    cout<<endl;

    return 0;
}
