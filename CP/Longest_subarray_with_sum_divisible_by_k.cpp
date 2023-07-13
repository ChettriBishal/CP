// https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/
#include<bits/stdc++.h>
using namespace std;


int longSubarrWthSumDivByK(int* arr,int n,int k)
{
    unordered_map<int,int> um;

    int pre[n]; // to store the prefix sum
    pre[0] = arr[0];
    for(int i=1;i<n;i++){
       pre[i] = pre[i-1] + arr[i]; 
    }

    int modarr[n]; // to store the modulo residue
    for(int i=0;i<n;i++){
        modarr[i] = (pre[i] %k + k) %k;
    }
    
    int res =0;
    for(int i=0;i<n;i++){
        if(modarr[i] == 0)
            res = i+1;
        else if(um.find(modarr[i]) == um.end())
            um[modarr[i]] = i;
        else
            if( i-um[modarr[i]] > res)
                res = i - um[modarr[i]];
    }

    return res;

}

int main()
{
    int arr[] = {2, 7, 6, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
     
    cout << "Length = "<< longSubarrWthSumDivByK(arr, n, k);
          
    return 0;    
}
