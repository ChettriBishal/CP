/*
    Bishal
    26-Apr-21 10:47:17 PM
    This seriously took a lot of time
 */
#include<bits/stdc++.h>
using namespace std;
struct cor{ // coordinates
    int x,y;
};
int epow(int a,int b)
{
    int res=1;
    while(b){   
        if(b&1) res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int distance(int a,int b,int c,int d) // square of distance between two coordinates
{   
    int dis=epow(a-c,2)+epow(b-d,2);
    return dis;
}
int main()
{
    cor xy[3]; // to store three coordinates
    for(int i=0;i<3;i++){   
        int a,b;
        cin>>a>>b;
        xy[i].x=a,xy[i].y=b;
    }
    int a[3]; // to store the square of distances
    for(int i=1;i<=3;i++){
        a[i-1]=distance(xy[i%3].x,xy[i%3].y,xy[(i+1)%3].x,xy[(i+1)%3].y);
    }
    sort(a,a+3);
    
    if(a[0]+a[1]==a[2]){ // checking if it's pythagorean triplet
        cout<<"RIGHT\n";
        return 0;
    }
    // now we check if increasing any point in any four directions would make it right angled or not
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    bool en=false;
   
    for(int i=0;i<3;i++)
    {
        cor check[3]; // to create the copy of the xy[] with one updated point
        
        for(int j=0;j<4;j++)
        {
            check[0].x=xy[i].x, check[0].y=xy[i].y;
            check[0].x+=dx[j],  check[0].y+=dy[j];
            
            int u=1;
            for(int k=0;k<3;k++){
                if(k!=i){
                    check[u].x=xy[k].x, check[u].y=xy[k].y;
                    u++;
                }
            }
            
            int bis[3];
            for(int i=1;i<=3;i++)
                bis[i-1]=distance(check[i%3].x, check[i%3].y,check[(i+1)%3].x,check[(i+1)%3].y);
            
            sort(bis,bis+3);
            bool zeroes=false;
            for(auto b: bis)
                if(b==0)zeroes=true;
            
            if(zeroes) continue; // if any side is zero then don't take that case
            

            if((bis[0]+bis[1])==bis[2]){
                en=true;
                break;
            }
        }
        if(en) break;
    }
    if(en) 
        cout<<"ALMOST\n";
    else
        cout<<"NEITHER\n";
    return 0;

}
/*
https://codeforces.com/problemset/problem/18/A
*/
