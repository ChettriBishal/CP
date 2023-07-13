#include <iostream>
#include <vector>
#include<string>
using namespace std;

vector<string> gss(string s){
    if(s.size() == 0){ // base case
        vector<string> res;
        res.push_back("");
        return res;
    }
    char ch = s[0];
    string exc = s.substr(1); // excluding the first character
  
    vector<string> res = gss(exc);
  
    vector<string> ok;
    for(auto &x: res){ // without considering ch 
        ok.push_back(x);
    }
    for(auto &x: res){
        ok.push_back(ch + x); // including ch 
    }
    
    return ok;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
