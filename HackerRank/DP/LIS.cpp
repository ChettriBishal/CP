// OLog(n) approach
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >>n;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;
    vector<int> lis;
    lis.push_back(arr[0]);
    for(int i=1;i < n;i++){
        if(arr[i] > lis.back()){
            lis.push_back(arr[i]);
        }
        else{
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            if(it != lis.end()){ // replace the element which is nearest greater to arr[i]
                *it = arr[i];
            }
        }
    }
    cout << lis.size() <<"\n";

    return 0;
}
