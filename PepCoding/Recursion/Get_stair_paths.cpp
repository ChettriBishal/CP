#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int n) {
    if(n == 0){
        vector<string> ok;
        ok.push_back("");
        return ok;
    }
  
    if(n < 0){
        vector<string> ok;
        return ok;
    }
  
    vector<string> path1, path2, path3;
  
    path1 = get_stair_paths(n-1);
    path2 = get_stair_paths(n-2);
    path3 = get_stair_paths(n-3);
  
    vector<string> res;
  
    for(auto &x: path1){
        x = "1" + x;
        res.push_back(x);
    }
    for(auto &x: path2){
        x = "2" + x;
        res.push_back(x);
    }
    for(auto &x: path3){
        x = "3" + x;
        res.push_back(x);
    }
    return res;
    
}

int main() {
  int n;
  cin >> n;
  vector<string> ans = get_stair_paths(n);
  int cnt = 0;

  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}
