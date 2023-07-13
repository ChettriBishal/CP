#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int &x:a)
        cin>>x;
    for(int i=1;i<=3100;i++)
    {
        auto it=find(a.begin(),a.end(),i);
        if(it==a.end()){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
/*
 * // start from the least value  
 * and search for one more than that #
 * if not present break 
 * else increment value of i by 1 and search again
 */
