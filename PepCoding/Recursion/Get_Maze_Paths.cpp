#include<iostream>
#include<vector>
using namespace std;

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr == dr && sc == dc){
        vector<string> ok;
        ok.push_back("");
        return ok;
    }
    vector<string> vpaths, hpaths;
    if(sr < dr){
        vpaths = getMazePaths(sr+1,sc,dr,dc);
    }
    if(sc < dc){
        hpaths = getMazePaths(sr,sc+1,dr,dc);
    }

    vector<string> paths;

    for(auto &x: hpaths){
        paths.push_back('h'+ x);
    }
    for(auto &x: vpaths){
        paths.push_back('v'+x);
    }

    return paths;
}

void display(vector<string>& arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) cout << ", ";
  }

  cout << "]" << endl;
}


int main() {
  int n, m;
  cin >> n >> m;

  vector<string> ans = getMazePaths(0, 0, n - 1, m - 1);

  display(ans);

}
