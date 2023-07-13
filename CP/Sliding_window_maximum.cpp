#include<bits/stdc++.h>
using namespace std;

void printkMax(int* arr, int n,int k)
{ 
    deque<int> ind; 
    for(int i=0;i<k;i++)
    {
        while(!ind.empty() && arr[i] >= arr[ind.back()])
            ind.pop_back();
        ind.push_back(i);
    }
    for(int i=k;i<n;i++){
        cout<<arr[ind.front()]<<" ";

        while(!ind.empty() && ind.front() <= i-k) // remove the elements not in window
            ind.pop_front();

        while(!ind.empty() && arr[i] >= arr[ind.back()])
            ind.pop_back();
        ind.push_back(i);
    }
    cout<<arr[ind.front()];
}

int main()
{
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printkMax(arr, n, k);
    return 0;
}
