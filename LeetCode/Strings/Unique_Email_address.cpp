class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> res;
        for(auto & email: emails){
            auto at_pos = find(email.begin(),email.end(),'@');
            auto end_after_removing_dots = remove(email.begin(),at_pos,'.');
            auto plus_pos = find(email.begin(),end_after_removing_dots,'+');
            email.erase(plus_pos, at_pos);
            res.insert(email);
        }
        return res.size();
    }
};
