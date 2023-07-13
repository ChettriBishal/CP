// Book Allocation: Binary Search 

#include<iostream>
#include<numeric>
#include<climits>
using namespace std;

bool ispossible(int* a,int n, int m, int minval)
{
    int student_used = 1;
    int pages_read = 0;

    for(int i=0;i<n;i++)
    {
        if(pages_read + a[i] > minval) // resetting for new slate
        {
            student_used++;
            pages_read = a[i]; // for the new student

            if(student_used>m){
                return false;
            }
        }
        else{ // for the current student
            pages_read += a[i];
        }
    }

    return true;
}


int findpage(int* a,int n, int m)
{
    // if no of books is less than the no of persons
    if(n<m){
        return -1; 
    }
    
    // count the no of pages
 
    int s = a[n-1];
    int e = accumulate(a,a+n,0);

    int res = INT_MAX;
    while(s<=e){
        int mid = (s+e)/2;

        if(ispossible(a,n,m,mid)){
           res = min(res,mid);
           e = mid-1;
        }
        else{
            // when it's not possible to divide at x pages
            // increase the no of pages
            s = mid+1;
        }
    }
    res = max(res,*max_element(a,a+n));
    return res;
}


void solve()
{
    int n,m;  // m--> number of students
    cin>>n>>m; // n--> number of books 
    int a[n];

    for(int&x: a) cin>>x;

    cout<<findpage(a,n,m)<<endl;

}


int main()
{
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }

    return 0;
}

/*
https://hack.codingblocks.com/app/practice/1/1365/problem

You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages.
Every student is assigned to read some consecutive books.
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
*/
