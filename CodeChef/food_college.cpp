/*
 * 11-Apr-21 8:41:35 PM
 * x=no of omlettes 
 * y=no of milkshakes 
 * z=no of cakes
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
    int N,E,H,A,B,C; // usual from the statement
    cin>>N>>E>>H>>A>>B>>C;
    int res=LLONG_MAX;
    for(int z=0;z<=N;z++){
        int e=E-z,h=H-z; // cause in case of cake it's unit for both
        if(e<0 or h<0) continue;
        int x=e/2,y=h/3,orders=N-z;
        if(x+y+z<N) continue; // if feasible orders is less than no of students
        int cost=z*C;
        if(A<=B){
            int mv=min(orders,x); // no of eggs
            cost+=(mv*A);
            orders-=mv; // reduced
            mv=min(orders,y); // no of milkshakes
            cost+=(mv*B);
            res=min(res,cost);
        }
        else{
            int mv=min(orders,y); // no of milkshakes
            cost+=(mv*B);
            orders-=mv;
            mv=min(orders,x); // no of eggs
            cost+=(mv*A);
            res=min(res,cost);
        }
    }    
    if(res==LLONG_MAX) cout<<-1<<endl;
    else cout<<res<<endl;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
A--> Cost of a omelette 
B--> Cost of a milkshake
C--> Cost of a cake

1 Omelette--> 2 eggs
1 Milkshake--> 3 chocolate bars
1 Cake---> 1 chocolate bar + 1 egg

Inequations:
x+y+z=N
2x+z<=E
3y+z<=H

*/
