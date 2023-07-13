class Solution{
    public:
    vector<set<int>> setOperations(set<int> a, set<int> b){
        vector<set<int>> res;
        vector<int> temp;
        set_union(a.begin(),a.end(),b.begin(),b.end(),back_inserter(temp));
        set<int> bis(temp.begin(),temp.end());
        res.emplace_back(bis);
        bis.clear(); temp.clear();
      
        
        set_difference(a.begin(),a.end(),b.begin(),b.end(),back_inserter(temp));
        if(temp.size()==0) 
            temp.push_back(0);
      
        bis.insert(temp.begin(),temp.end());
        res.emplace_back(bis);
        bis.clear(); temp.clear();
        
      
        set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(temp));
        if(temp.size()==0) 
            temp.push_back(0);
      
        bis.insert(temp.begin(),temp.end());
        res.emplace_back(bis);
        bis.clear(); temp.clear();
        
        return res;
        
    }
};


/*
Given two sets A and B of size N and M . 
Perform set operation i.e union, intersection and difference on sets using set_union, set_difference and set_intersection functions of STL.
Input: N = 4, M = 5
A = {1, 2, 3, 4}
B = {3, 4, 5, 6, 7}

Output:
1 2 3 4 5 6 7
1 2
3 4


Explaination: 
Union of two sets A (1 2 3 4) and 
B (3 4 5 6 7) is (1 2 3 4 5 6 7).
Difference A-B is 1 2.
The intersection is 3 4.

*/
