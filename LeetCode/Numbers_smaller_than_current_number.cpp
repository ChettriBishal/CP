class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& a) {
        int n = a.size();
        int cnt[103];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            cnt[a[i]]++;
        }
        for(int i=1;i<=100;i++){
            cnt[i] += cnt[i-1];
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(a[i]-1 >=0)
                res.push_back(cnt[a[i]-1]);
            else
                res.push_back(0);
        }
        return res;
    }
};
