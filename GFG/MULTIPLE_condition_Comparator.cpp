// comparator function as per the requirements
bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
{
    if(a.first == b. first){
        if(a.second.first == b.second.first){
            return a.second.second < b.second.second;
        }
        return a.second.first > b.second.first;
    }
    return a.first < b.first;
}

class Solution{
    public:
    void customSort (int phy[], int chem[], int math[], int N)
    {
        vector<pair<int,pair<int,int>>> marks;
        for(int i=0;i<N;i++){
            marks.push_back({phy[i],{chem[i],math[i]}});
        }
        sort(marks.begin(),marks.end(),comp); 
        int i=0;
        for(auto k: marks){
            phy[i] = k.first;
            chem[i] = k.second.first;
            math[i] = k.second.second;
            i++;
        }
    } 
};
