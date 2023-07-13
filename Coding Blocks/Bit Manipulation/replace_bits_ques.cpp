#include<bits/stdc++.h>
using namespace std;
int clear_range(int n,int i,int j)
{
    int a=(~0)<<(j+1); // mask a
    int b=(1<<i)-1;  // mask b
    int mask=a | b;
    n=n & mask;
    return n;
}
void binaryrep(int n)
{
    string s=bitset<16>(n).to_string();
    cout<<s<<"\n";
}
void replace_range(int &n,int m,int i,int j)
{
    int c_n=clear_range(n,i,j); // first clear the range
    int d=(m<<i); // to add i zeroes at right 
    cout<<"cleared N:                  ";
    binaryrep(c_n);
    cout<<"M with i zeroes (at right): ";
    binaryrep(d);
    n=c_n|d;
    cout<<"Final N:                    ";
    binaryrep(n);
    cout<<n<<"\n";

}

int main()
{
    cout<<"Enter for N: ";
    int N; cin>>N;
    string s=bitset<16>(N).to_string();
    cout<<"N: "<<s<<endl;
    cout<<"Enter integer M and indices I and J to replace in N\n";
    int M,i,j;
    cin>>M>>i>>j;
    cout<<"M: ";
    binaryrep(M);
    replace_range(N,M,i,j);

    return 0;
}
/*
 * Consider N = 15 , M=2, I=1, J=3 
 *  Res= 5
 *  */
