/* To find the maximum subarray sum for an array 
 * Bottom Up DP
*/
#include<iostream>
#include<algorithm>
using namespace std;

int maxSubarraysum(int* a,int n)
{
    int dp[100]= {0};

    dp[0] = a[0]> 0? a[0]: 0;
    
    int max_so_far = dp[0];

    for(int i=1;i<n;i++){
        dp[i] = dp[i-1] + a[i]; 
        if(dp[i] < 0){
            dp[i] = 0;
        }
        max_so_far  = max(dp[i],max_so_far);
    }

    return max_so_far ;
}

// Space optimised Code
// Kadane's Algorithm
int maxSubsumSpaceOptimised(int* a,int n)
{
    int current_sum = 0;
    int max_so_far = 0;

    bool allnegative = true;
    for(int i=0;i<n;i++)
    {
        if( a[i] > 0 ){
            allnegative = false;
        }

        current_sum += a[i];

        if(current_sum < 0){
            current_sum = 0;
        }
        
        max_so_far = max(current_sum , max_so_far);
    }
    if(!allnegative)
        return max_so_far;
    else
        return *min_element(a,a+n);
}

// Special Case 
// If all elements are negative you need to output the smallest negative element 


int main()
{
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n= sizeof(arr)/sizeof(int);

    cout<<maxSubarraysum(arr,n)<<endl;

    cout<<maxSubsumSpaceOptimised(arr,n)<<endl;

    return 0;
}
