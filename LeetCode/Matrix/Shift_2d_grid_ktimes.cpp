class Solution {
    public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // firstly we convert the index in terms of 1 d array with k shifts
        // and then convert it into 2 d matrix based index
        int m = grid.size();
        int n = grid[0].size();
        int tot = m * n; // total number of elements
        if(k % tot == 0)
            return grid;
        
        vector<vector<int>> res(m, vector<int> (n));
        for(int i= 0;i<tot;i++){ // iterating over like in 1d array of m * n elements
            int movedin= (i + k) % tot; // after k shifts
            res[movedin/n][movedin%n] = grid[i/n][i%n]; // gettting 2-d index from 1 d
        }
        return res;
       }
};
// here "movedin" is in terms of 1 D array
