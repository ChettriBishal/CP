#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<string>s;
    int h,w,x,y;
    cin>>h>>w>>x>>y;
    --x;
    --y;
    for(int i=0;i<h;i++)
    {
        string g;
        cin>>g;
        s.push_back(g);
    }
    int cnt=0;
    for(int i=y;i<w;i++){ // row wise --->
        if(s[x][i]=='#') break;
        else cnt++;
    }
    for(int i=y-1;i>=0;i--){ // row wise <---
        if(s[x][i]=='#') break;
        else cnt++;
    }
    for(int i=x+1;i<h;i++){ // col wise down
        if(s[i][y]=='#') break;
        else cnt++;
    }
    for(int i=x-1;i>=0;i--){ // col wise up
        if(s[i][y]=='#') break;
        else cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
