class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto comp = [](vector<int> & a, vector<int> &b){
            int x1,y1,x2,y2;
            x1 = a[0], y1 = a[1];
            x2 = b[0], y2 = b[1];
            double one = (double) sqrt(x1 * x1 + y1 * y1);
            double two = (double) sqrt(x2 * x2 + y2 * y2);
            return one > two;
        };
        
        priority_queue<vector<int>,vector<vector<int>>, decltype(comp)>  pq(comp);
        
        vector<vector<int>> result;
        
        for(int i=0;i<points.size();i++){
            pq.push(points[i]);
        }
        
        while(k--){ // top k closest points 
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
    }
};
