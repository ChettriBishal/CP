class NumArray {
public:
    int* segTree;
    inline static int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree = new int[4*n + 3];
        
        buildTree(nums, 0, n-1,1);    
    }
    void buildTree(vector<int> & nums, int s, int e, int index){
        if(s == e){
            segTree[index] = nums[s];            
            return;
        }
        int mid = (s + e)/2;
        
        buildTree(nums, s, mid, 2 *index);
        buildTree(nums, mid+1, e, 2 * index +1);
        
        segTree[index] = segTree[2* index] + segTree[2 * index + 1];
        
    }
    
    void update(int i, int val, int s = 0, int e = n-1, int index = 1){
        if(s == e){
           segTree[index] = val;
           return;
        }
        
        int mid = (s + e)/2;
        
        if(i <= mid)
            update(i, val,s, mid, 2 * index);
        else
            update(i, val,mid+1, e, 2 * index + 1);
        
        segTree[index] = segTree[2 * index] + segTree[2 * index + 1];
        
    }
    
    int query(int qs,int qe, int ss, int se, int index){
        if(qs <= ss && qe >= se) // complete overlap
            return segTree[index];
        
        if(qs > se || ss > qe) // no overlap
            return 0;
        
        // partial overlap
        
        int mid = (ss + se) /2;
        
        int left = query(qs, qe, ss, mid, 2 * index);
        int right = query(qs, qe, mid+1, se, 2 * index + 1);
        
        return left + right;
        
    }
    
    int sumRange(int left, int right) {
        if(left > right) 
            return 0;  
        
        return query(left, right, 0, n-1,1);
    }
    

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
