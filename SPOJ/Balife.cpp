#include<iostream>
#include<cmath>
#include<climits>
typedef long long ll;
using namespace std;

bool is_integer(float k) // to check if it is an integer
{
    return floor(k) == k;
}
void solve(int n)
{ 
    ll a[n];
    ll sum = 0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }

    // load to be divided among every cell
    float every_cell = (float) sum /n;
    if(!is_integer(every_cell)){
        cout<<-1<<endl;
        return ;
    }

    ll sum_so_far = 0; // keep track of the sum for the indices traversed so far
    int left_cells = 0; // [0, left_cells]
    ll res = INT_MIN;
    for(int i= 0;i<n;i++){
        left_cells++;
        sum_so_far += a[i];
        ll check = every_cell * left_cells; // value supposed to be on the left side 
        check = abs(sum_so_far - check); // amount of load transfer needed
        res = max(res,check);
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef Bis
    freopen("input.txt","r",stdin);
#endif
    int n;
    while(cin>>n){
        if(n == -1) break;
        solve(n);
    }
    return 0;
}
