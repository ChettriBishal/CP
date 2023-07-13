/* https://www.codechef.com/COOK131B/problems/XORORED */
#include<iostream>
#include<vector>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int X = 0;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        X |= a[i];
    }
    // now that x is calculated calcuated xor it with all elements 
    int OR = 0; // and calculate the OR
    for(int val: a){
        val ^=X;
        OR |=val;
    }
    // then find the OR of the values
    cout<<X<<" "<<OR<<endl;

}


int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
