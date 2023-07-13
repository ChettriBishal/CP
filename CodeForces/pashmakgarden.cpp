#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c,d;
    cin>>a>>b>>c>>d;// the coordinates for the first one 
    if(a==c){ // like 00 01 ie x coordinates are same  //y doesn't change
        cout<<a+abs(b-d)<<" "<<b<<" "<<c+abs(b-d)<<" "<<d<<endl; //abs(b-d)=length of side
    }
    else if(b==d){// like 00 10 ie y coordinates are the same //x doesn't change
        cout<<a<<" "<<b+abs(a-c)<<" "<<c<<" "<<d+abs(a-c)<<endl; //abs(b-c)= length of side
    }
    else if(abs(a-c)==abs(b-d)){// this one's for the diagonal cases like 01 10
        cout<<a<<" "<<d<<" "<<c<<" "<<b<<endl;
    }
    else 
        cout<<-1<<endl;
    return 0;
}