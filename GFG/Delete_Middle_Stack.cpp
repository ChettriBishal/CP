class Solution
{
    public:
    
    void deleteMid(stack<int>&s, int n,int cur =0)
    {
         if( cur == n || s.empty()){
            return;
        }
        int x = s.top();
        s.pop();
        deleteMid(s,n,cur+1);
        
        // put all items back except the middle one
        if(cur != n/2){
            s.push(x);
        }
    }
};
