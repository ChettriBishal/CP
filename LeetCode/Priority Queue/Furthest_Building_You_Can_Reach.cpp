class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>, greater<int>> pq;
        
        for(int i=0;i < heights.size() -1;i++){
            int dist = heights[i+1] - heights[i];
            if(dist > 0){
                pq.push(dist);
            }
            if(pq.size() > ladders){
                bricks -= pq.top();
                pq.pop();
            }
            if(bricks < 0)
                return i;
        }
        
        return heights.size() -1;
    }
};

/*
If the size of queue exceed ladders,
it means we have to use bricks for one move.
Then we pop out the smallest difference, and reduce bricks.
If bricks < 0, we can't make this move, then we return current index i.
If we can reach the last building, we return A.length - 1
*/
