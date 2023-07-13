#include<bits/stdc++.h>
using namespace std;
bool check(int a[],int r2,int c2,int d2)
{
    if(a[0]==a[3]) return false; // checking if pairwise distinct
    if(a[1]==a[2]) return false;
    if(a[0]==a[1]) return false;
    if(a[0]==a[2]) return false;
    if(a[2]==a[3]) return false;
    if(a[1]==a[3]) return false;
    for(int i=0;i<4;i++)
    {
        if(a[i]>=1 and a[i]<=9){}
        else return false;
    } 
    if(a[2]+a[3]!=r2) return false;
    if(a[1]+a[3]!=c2) return false;
    if(a[1]+a[2]!=d2) return false;
    return true;
}
int main()
{
    int a[4]={0};
    int r1,r2,c1,c2,d1,d2;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    a[0]=(r1+c1-d2)/2;
    a[1]=r1-a[0];
    a[2]=c1-a[0];
    a[3]=d1-a[0];
    if(check(a,r2,c2,d2)){
        for(int i=0;i<4;i+=2)
            cout<<a[i]<<" "<<a[i+1]<<endl;
    }
    else 
        cout<<-1<<endl;
    return 0;

}
