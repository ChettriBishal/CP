#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n<m)
        cout<<-1<<endl;
    else
    {
        int  l=(n+1)/2; //l is the lower bound [n/2,n]
        cout<<(l+m-1)/m*m<<endl; //minimum number that is multiple of m 
    }
    
    return 0;   
}