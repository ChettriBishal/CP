/*
You are given two arrays A and B each containing N numbers. 
You need to choose exactly one number from A and exactly one number from B
such that the index of the two chosen numbers is not same and the sum of the 2 chosen values is minimum.
Formally, if you chose ith element from A whose value is x and jth element from B whose value is y, 
you need to minimize the value of (x+y) such that i is not equal to j.
Your objective is to find this minimum value.

NOTE: If not possible print "-1" without quotes.
*/

#include<bits/stdc++.h>
using namespace std;
long long getMin(long long A[], long long B[], long long n)
{
    if( n == 1 ){
        return -1;
    }
    vector<pair<long long ,int> > a;
    vector<pair<long long , int> > b; 

    for(int i= 0;i<n;i++){
        a.push_back({A[i],i});
        b.push_back({B[i],i});
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    long long res = INT_MAX;

    // manipulating the fact that we'll get the lowest sum from the first two elements of both the arrays 

    for(int i=0;i<n && i<2;i++){
        for(int j =0;j<n && j<2;j++){
            if(a[i].second != b[j].second){
                res = min(res,a[i].first+ b[j].first);
            }
        }
    } 

    return res;

}

int main()
{
    long long A[5] = {5, 4, 3, 2, 1};
    long long B[5] = {1, 2, 3, 4, 5};
    long long x = getMin(A,B,5);

    cout<<x<<endl;
    return 0;
}
