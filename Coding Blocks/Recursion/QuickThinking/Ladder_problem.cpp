#include<iostream>
using namespace std;

int f(int n, int k)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;

    int res=0;

    for(int i=1;i<=k;i++){
        res+=f(n-i,k);
    }

    return res;

}

int main()
{
    cout<<"Enter value for n and k\n";
    int n,k;
    cin>>n>>k;
    cout<<f(n,k)<<endl;

    return 0;
}
