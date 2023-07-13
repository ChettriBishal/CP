#include<bits/stdc++.h> //bis
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main()
{
    io;
    int row,col;
    cin>>row>>col;
    char s[10][10];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
           cin>>s[i][j];
    }
    int sum=0,c,flag=0,flg=0;
    for(int i=0;i<row;i++)
    {
        c=0;
        for(int j=0;j<col;j++)
        {
            if(s[i][j]!='S') c++;
            else{
                c=0;
                break;
            }
        }
        if(c==col){ //using flag to later deduct the intersections
            flag++;
            sum+=c;
        }
    }
    if(flag==row){
        cout<<sum<<endl;
        return 0;
    }
    else{
        for(int i=0;i<col;i++)
        {
            c=0;
            for(int j=0;j<row;j++)
            {
                if(s[j][i]!='S') c++;
                else{
                    c=0;
                    break;
                }
            }
            if(c==row){ //using flg to deduct the intersections
                sum+=c;
                flg++;
            }
        }
    }
    cout<<sum-flg*flag<<endl;
    return 0;
}
    
        
        
        