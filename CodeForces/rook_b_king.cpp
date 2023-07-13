#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    // firstly the rook
    if(a==c or b==d)
        cout<<1<<" ";
    else 
        cout<<2<<" ";
    // now for the bishop
    if((a+b)%2!=(c+d)%2)cout<<0<<" ";
    else{
        if(a+b==c+d or a-b==c-d)
            cout<<1<<" ";
        else
            cout<<2<<" ";
    }
    // finally the king
    cout<<max(abs(a-c),abs(b-d));
    return 0;
}
