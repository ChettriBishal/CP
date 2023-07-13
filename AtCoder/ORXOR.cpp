/*
10-Apr-21 1:41:36 PM
*/
#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int &x:a)
        cin>>x;
    int res=INT_MAX;
    for(int i=0;i<(1<<(n-1));i++){
        int xored=0,ored=0; 
        for(int j=0;j<=n;j++){
            if(j<n) ored|=a[j]; // to handle the out of bounds index when j=n
            if(j==n or (i&(1<<j))) xored^=ored, ored=0;
        }
        res=min(res,xored);
    }
    cout<<res<<endl;
    return 0;
}
/*
 * Bitmasking for subsets generation 
 * 0  0  0  0  0  0 ----> 5 items
 *  ^   ^  ^  ^  ^  ----> 4 divisions at max possible
 * One subset will contain the elements to be ored 
 * Finally the ored value in every subset will need to be xored with the same of every other subset
 */
