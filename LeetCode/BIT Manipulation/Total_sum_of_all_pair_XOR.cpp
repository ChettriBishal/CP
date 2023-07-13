/*
 Total sum of all pair XOR 
 This question reduces to finding :
 How many pairs have ith bit set ?
 Then using that information we can construct the number itself
*/

#include<iostream>
using namespace std;
int main()
{
    int n, res=0;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<32;i++){
        int cntZ = 0, cntO = 0; // count of zero and one
        for(int j =1;j<=n;j++){
            if(arr[j] & ( 1<<i ))  // check if the jth element has ith bit set 
                cntO++;
            else
                cntZ++;
        }
        int pairs = cntO * cntZ;  // total number of pairs

        res += (pairs * (1<<i));
    }

    cout<<res<<endl;
}
/*
 For arr = 5 3 9
 sum = 5^3 + 5^9 + 3^9 = 28
 5 ^ 3 = 0 1 1 0
 5 ^ 9 = 1 1 0 0
 3 ^ 9 = 1 0 1 0
         <------ i
         Summation of --> count of pairs * 2 ^ base 
         0 * (2 ^ 0) + 2 * (2 ^ 1) + 2 * (2 ^ 2) + 2 * (2 ^ 3) = 28 
*/
