#include<iostream>
#include<climits>
using namespace std;
#define int long long 
bool ispossible(int n,int m, int x, int y, int stud_cnt)
{

    int coupons_required = stud_cnt * x; // every student requires X coupons to get scholarship

    int coupons_available = (n-stud_cnt) * y + m;  // coupons already provided by CB + coupons taken from other students

    if(coupons_available >= coupons_required)
        return true;
        
    return false;

}

signed main()
{
    int n,m,x,y;

    cin>>n>>m>>x>>y;

    int s = 0;
    int e = n; 

    int res = LLONG_MIN;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(ispossible(n,m,x,y,mid)){
            res = max(res,mid);
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    cout<<res<<endl;

    return 0;
}
