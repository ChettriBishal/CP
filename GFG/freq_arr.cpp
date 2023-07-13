class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencycount(vector<int>& a,int n)
    { 
        for(int i=0;i<n;i++) // for elements to be in range
            a[i]-=1;
        for(int i=0;i<n;i++)
            a[a[i]%n]+=n;
        for(int i=0;i<n;i++)
            a[i]=a[i]/n;
    }
};
