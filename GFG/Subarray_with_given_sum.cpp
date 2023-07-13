#include<iostream>
#include<vector>
using namespace std;

/* Add elements one by one to curr_sum and
*  if the curr_sum exceeds the sum,
*      then remove starting element */

vector<int> subarraysum(int * a, int n , int sum)
{

	/* Initialize curr_sum as value of
	first element and starting point as 0 */
    int curr= a[0], start = 0;

    for(int i=1;i<=n;i++){

		/* If curr_sum exceeds the sum,
		then remove the starting elements */
        while(curr > sum && start < i-1){
            curr -= a[start];
            start++;
        }

        if(curr == sum){
            return {start+1,i};
        }

        if(i<n){
            curr += a[i];
        }
    }

    return {-1};

}

int main()
{
    
    int a[]= {1,2,3,7,5};
    int n= sizeof(a)/sizeof(int);
    int s= 12;

    vector<int> res = subarraysum(a,n,s);

    for(auto k: res){
        cout<<k<<" ";
    }



    return 0;
}

