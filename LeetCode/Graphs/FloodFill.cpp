class Solution {
public:
    vector<int> dx{-1,0,1,0};
    vector<int> dy{0,1,0,-1};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        
        if(color != newColor)
            dfs(image,sr,sc,color, newColor);
        
        return image;
    }
    void dfs(vector<vector<int>> & image,int sr, int sc,int color, int newColor){
        
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size())
            return;
        
        if(image[sr][sc] != color)
            return;
        
        image[sr][sc] = newColor;
        
        for(int k=0;k< 4;k++)
            dfs(image,sr + dx[k], sc + dy[k], color, newColor);
    }
};
