#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"Enter a string to find all subsets of the characters\n";
    string s;
    cin>>s;
    int n= (int) s.length();
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++){
            if(i & (1<<j))  // checking if the bits are set
                cout<<s[j];
        }
        cout<<endl;
    }

    return 0;
}
