class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int temp[numRows+1][numRows+1];
        memset(temp,0,sizeof(temp));
        int n= numRows;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j == i)
                    temp[i][j] = 1;
                else{
                   temp[i][j] = temp[i-1][j-1] + temp[i-1][j]; 
                }
            }
        }
        vector<vector<int>> res(n);
        int k=1;
        for(int i= 0;i< n;i++){
            for(int j=0;j<k;j++){
                res[i].push_back(temp[i+1][j+1]);
            }
            k++;
        }
        return res;
        
    }
};
