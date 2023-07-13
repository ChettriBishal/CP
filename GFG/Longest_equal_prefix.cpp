/*
Given two positive integers x and y, and an array arr[] of positive integers. 
We need to find the longest prefix index which contains an equal number of x and y. 
Print the maximum index of largest prefix if exist otherwise print -1.
*/

int findIndex(int a[], int x, int y, int n)
{
    int nx = 0, ny = 0;
    int res=-1;
    
    for(int i= 0;i<n;i++ ){
        nx += (x == a[i]);
        ny += (y == a[i]);
        
        if(nx!=0 && nx == ny){
            res = i;
        }
    }
    return res;
}

/*
Input:
N=11
X=7  Y=42
arr[] = [ 7, 42, 5, 6, 42, 8, 7, 5, 3, 6, 7 ]
Output: 9

Explanation: The longest prefix with same 
number of occurrences of 7 and 42 is:
7, 42, 5, 6, 42, 8, 7, 5, 3, 6 
*/
