class Solution {
public:
    bool monoinc(vector<int>& a,int l){
        if(l == a.size()-1) return true;
        if(a[l] <= a[l+1] && monoinc(a,l+1))
            return true;
        else return false;
        
    }
    bool monodec(vector<int>& a,int l){
        if(l == a.size()-1) return true;
        if(a[l] >= a[l+1] && monodec(a,l+1))
            return true;
        else return false;
        
    }
    bool isMonotonic(vector<int>& nums) {
        if(monoinc(nums,0) || monodec(nums,0))
            return true;
        return false;
    }
};
