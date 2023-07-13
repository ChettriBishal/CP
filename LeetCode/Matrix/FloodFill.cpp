class Solution {
public:
    map<pair<int,int>,list<pair<int,int>> > l;
    int rows, cols;
    map<pair<int,int>, bool> added;
  
    void add(int x, int y, vector<vector<int>>& image){  // adding the edges
        if(added[{x,y}] == true)
            return;
        //cout<<"HERE "<<x<<" "<<y<<endl;
        added[{x,y}] = true;
        if(x + 1 < rows && image[x][y] == image[x+1][y]){
            l[{x,y}].push_back({x+1,y});
            l[{x+1,y}].push_back({x,y});
            add(x+1,y,image);
        }
        if(x - 1 > -1 && image[x][y] == image[x-1][y]){
            l[{x,y}].push_back({x-1,y});
            l[{x-1,y}].push_back({x,y});
            add(x-1,y,image);
        }
        if(y +1 < cols && image[x][y] == image[x][y+1]){
            l[{x,y}].push_back({x,y+1});
            l[{x,y+1}].push_back({x,y});
            add(x,y+1,image);
        }
        if(y -1 > -1 && image[x][y] == image[x][y-1]){
            l[{x,y-1}].push_back({x,y-1});
            l[{x,y-1}].push_back({x,y});
            add(x, y-1,image);
        }
            
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        rows = image.size();
        cols = image[0].size();

        add(sr, sc, image);
        queue<pair<int,int>> q;
        map<pair<int,int>, bool> visited;
        
        q.push({sr,sc});
        while(!q.empty()){
            pair coor = q.front();
            q.pop();
            visited[coor] = true;
            //cout<<coor.first<<" "<<coor.second<<endl;
            image[coor.first][coor.second] = newColor;
            for(auto & ls: l[coor]){
                if(visited[ls] == false){
                    q.push(ls);
                    image[ls.first][ls.second] = newColor;
                    visited[ls] = true;
                }
            }
        }
        return image;
    }
};
