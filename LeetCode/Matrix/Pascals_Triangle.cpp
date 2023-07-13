class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int temp[numRows + 1][numRows + 1];
        memset(temp,0,sizeof(temp));
        for(int i=1;i<= numRows; i++){
            for(int j=1;j<=numRows; j++){
                if(i == j)
                    temp[i][j] = 1;
                else
                    temp[i][j] = temp[i-1][j] + temp[i-1][j-1];
            }
        }
        vector<vector<int>> res(numRows);
        int k = 1; // no of elements at every level
        for(int i=0;i<numRows;i++){
            for(int j = 0;j<k;j++){
                res[i].push_back(temp[i+1][j+1]);
            }
            k++; // for the next level
        }
        return res;
    }
};
