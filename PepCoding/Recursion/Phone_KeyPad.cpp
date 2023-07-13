#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> phone{".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

vector<string> getKPC(string s) {
    if(s.empty()){ //  base case
        vector<string> res;
        res.push_back("");
        return res;
    }
    int dig = s[0] - '0';
    
    string ahead = s.substr(1);
    
    vector<string> temp = getKPC(ahead);
    
    string curr = phone[dig];
    
    vector<string> ok;
    for(int i=0;i < curr.size();i++){
        char x = curr[i];
        for(auto &ch: temp){
            ok.push_back(x + ch);
        }
    }
    return ok;
}


int main() {
  string s;
  cin >> s;
  vector<string> ans = getKPC(s);
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
