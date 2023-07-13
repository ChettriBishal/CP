class solution{
public:
    vector<int> removeDuplicate(vector<int>& a, int n)
    {
        vector<int> res;
        int bis[101];
        for(int i= 0;i<n;i++){
            bis[a[i]]++;
        }
        for(int i=0;i<n;i++){
            if(bis[a[i]] != -1){
                res.push_back(a[i]);
                bis[a[i]] = -1;
            }
        }
        return res;
    }
};
