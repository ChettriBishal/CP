/*
 You are given N number of books. Every ith book has Ai number of pages. 
 You have to allocate books to M number of students. There can be many ways or permutations to do so.
 In each permutation, one of the M students will be allocated the maximum number of pages.
 Out of all these permutations, the task is to find that particular permutation in which
 the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 
 Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
 */
#include<bits/stdc++.h>
#include"bistimulus.h"
using namespace std; 

bool possible(int* a,int n,int m,int minpages )
{
    int pages_read = 0;
    int students_used = 1;

    for(int i=0;i<n;i++){
        if(a[i] + pages_read > minpages){
            students_used ++;
            pages_read = a[i]; // for new student used
            if(students_used > m){
                return false;
            }
        }
        else{
            pages_read += a[i];
        }
    }

    return true;
}

int maximumpagesmin(int* a,int n,int m)
{
    if( n< m ){
        return -1;
    }

    debug(n);
    debug(m);
    sort(a,a+n);
    int s= a[n-1];
    int e= accumulate(a,a+n,0);

    int res = INT_MAX;
    while(s <= e){
        int mid = (s + e)/2;
        if( possible(a,n,m,mid) ){
            res = min( res, mid );
            e = mid -1;
        }
        else
            s = mid +1;
    }
    res= max(res,*max_element(a,a+n));
    return res;
}


int main()
{

    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    getchar();
    cin>>m;
    cout<<maximumpagesmin(a,n,m)<<endl;

    return 0;
}
