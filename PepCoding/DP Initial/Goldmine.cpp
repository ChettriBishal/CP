//#include "bistimulus.h"
/*

1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from 
     any row in the left wall.
5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
6. Each cell has a value that is the amount of gold available in the cell.
7. You are required to identify the maximum amount of gold that can be dug out from the mine.

*/
#include <bits/stdc++.h>

using namespace std;


int collectGold(int n, int m, vector<vector<int>>& arr, vector<vector<int>>& dp) {


    // base case last column 
    for(int i= 0;i < n;i++) {
        dp[i][m-1] = arr[i][m-1];
    }

    for(int j = m -2; j >= 0;j--){
        for(int i = 0;i < n;i++){
            dp[i][j] = arr[i][j];

            int addup = 0; // three choices
            if(i -1 >= 0) addup = max(addup, dp[i-1][j+1]);
            if(i + 1 < n) addup = max(addup, dp[i+1][j+1]);
            addup = max(addup, dp[i][j+1]);

            dp[i][j] += addup;

        }
    }

    int res = 0; // return the max val from the first column
    for(int i=0; i < n;i++){
        res = max(res, dp[i][0]);
    }

    return res;

}


int main() {

#ifdef Bis
    freopen("input.txt","r",stdin);
#endif

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << collectGold(n, m, arr, dp);

}
