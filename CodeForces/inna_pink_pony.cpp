#include<bits/stdc++.h>
using namespace std;
struct corners{ // to store the corner coordinates
    int x,y;
};
int main()
{
    int n,m,i,j,a,b;
    cin>>n>>m>>i>>j>>a>>b;
    corners c[4];
    c[0].x=n,c[0].y=m;
    c[1].x=1,c[1].y=1;
    c[2].x=1,c[2].y=m;
    c[3].x=n,c[3].y=1;
    int res=INT_MAX;
    for(int k=0;k<4;k++)
    {
        int dx, dy;
        dx=abs(c[k].x-i),dy=abs(c[k].y-j);
        if(dx && dy && dx%a==0 && dy%b==0 && abs(dx/a-dy/b)%2==0) 
            res=min(res,max(dx/a,dy/b));
        else if(dx==0 && dy==0){
            res=0;
            break;
        }
        else if(dx==0 && a<=n-1 && dy%b==0 && (dy/b)%2==0)
            res=min(res,dy/b);
        else if(dy==0 && b<=m-1 && dx%a==0 && (dx/a)%2==0)
            res=min(res,dx/a);
    }
    if(res!=INT_MAX)
        cout<<res<<"\n";
    else 
        cout<<"Poor Inna and pony!\n";
    return 0;
}
/*
 * abs(dx-dy)%2==0 ensures both dx and dy are either odd or even
 * Lets find a solution for shifting a candy from the position (x1, y1) into position (x2, y2). On each step we shift
 * (increase or decrease) x1 by a and y1 by b.
 *
 * It is not difficult to understand that if |x2 - x1| is not divisible by a and |y2 - y1| is divisible by b answer
 * doesn't exist.
 *
 * We should also note that |x2 - x1| / a and |y2 - y1| / b Should be both even or odd as shifting is performed at a
 * time for both values.
 *
 * We should also look up for a corner case when step drops us out from the board.
 *
 * Now we can determine the way from (x1, y1) to (x2, y2) as max(|x1 - x2| / a, |y1 - y2| / b).
 *
 * Lets calculate it for all corners and choose minimum or determine that the answer doesn't exist.
 */
