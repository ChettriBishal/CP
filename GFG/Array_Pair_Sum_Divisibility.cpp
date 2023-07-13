/*
Given an array of integers and a number k,
write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

Example 1 :

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

*/
#include<bits/stdc++.h>
using namespace std;

bool canPair(vector<int> nums,int k)
{
    if((int)nums.size()&1)
        return false;

   unordered_map<int,int> freq;

    for(int i=0;i<(int)nums.size();i++){
        int rem = (k+ (nums[i]% k)) %k;
        freq[rem]++;
    }
    
    for(int i=0;i<(int)nums.size();i++)
    {
        int rem = (k+ (nums[i]%k))%k;
        // if rem is half of that of k
        // means there must be even numbers of those
        if(rem* 2 == k){
            if(freq[rem] & 1){ // if not even 
                return false;
            }
        }
        else if(rem == 0){
            if(freq[rem]&1){
                return false;
            }
        }
        else if(freq[rem] != freq[k-rem]){
            return false;
        }
    }
    return true;

}


int main()
{
    cout<<"Enter the size of the array\n";
    int n;
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the elements\n";
    for(int &x: a) cin>>x;

    cout<<"Enter the value  of k\n";
    int k; cin>>k;
    
    if(canPair(a,k)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;

}
