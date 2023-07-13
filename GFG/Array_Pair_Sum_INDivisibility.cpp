/* https://www.geeksforgeeks.org/subset-no-pair-sum-divisible-k/

Given an array of integer numbers, we need to find maximum size of a subset such that sum of each pair of this subset is not divisible by K. 
Examples : 
 

Input :  arr[] = [3, 7, 2, 9, 1]        
         K = 3
Output : 3
Maximum size subset whose each pair sum 
is not divisible by K is [3, 7, 1] because,
3+7 = 10,    
3+1 = 4,    
7+1 = 8        all are not divisible by 3.
It is not possible to get a subset of size 
bigger than 3 with the above-mentioned property.

Input : arr[] = [3, 17, 12, 9, 11, 15]
        K = 5
Output : 4  

*/

int subsetPairNotDivisibleByK(int a[], int n, int k) 
{
    int freq[k] = {0}; // to store the frequency of the remainders
    for(int i=0;i<n;i++){
        int rem = (a[i])%k;
        freq[rem]++;
    }
    int res = min(freq[0],1); // the maximum size of the subset required
    
    if(k % 2 == 0) // if k is divisible by 2 then k/2 as a remainder is likely
        freq[k/2] = min(1,freq[k/2]);
        
    for(int i=1;i<=k/2;i++){ // looping till k/2 as we're including in pairs i & k-i
        res += max(freq[i],freq[k-i]);
    }
    
    return res;
    
}
/*
We can solve this problem by computing modulo of array numbers with K.
if sum of two numbers is divisible by K, then if one of them gives remainder i, other will give remainder (K – i).
First we store frequencies of numbers giving specific remainder in a frequency array of size K. 
Then we loop for all remainders i and include max(f[i], f[K – i]). 
Why? a subset with no pair sum divisible by K must include either elements with remainder f[i] or with remainder f[K – i].
Since we want to maximize the size of subset, we pick maximum of two sizes. 
In below code array numbers with remainder 0 and remainder K/2 are handled separately.
If we include more than 2 numbers with remainder 0 then their sum will be divisible by K, 
so we have taken at max 1 number in our consideration, same is the case with array numbers giving remainder K/2.

*/
