#include<iostream>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<int,int>,
null_type,
less<pair<int,int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main()
{
    // considering array without duplicates
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    ordered_set st;
    int inv_cnt=0; // inversion count
    cout<<"a[i]    inv_cnt"<<"\n";
    for(int i=0;i<n;i++){
        int cnt=st.size()-st.order_of_key({a[i],i});
        inv_cnt+=cnt;
        st.insert({a[i],i});
        cout<<a[i]<<"       "<<cnt<<"\n";
    }
    cout<<"\n";
    cout<<"Inversion Count: "<<inv_cnt<<"\n";
    cout<<"\nSet: {Value-index} mapping "<<"\n";
    cout<<"\nValue    Index\n";
    for(auto k=st.begin();k!=st.end();k++)
        cout<<k->first<<"         "<<k->second<<"\n";
    return 0;
}
/*
 * The idea here is to store duplicate values by making pairs with index of the array
 * In this way every pair is stored while we operate on the element which is stored as first
 * The second is merely a way to allow us to store them as distinct pairs 
 * 
 * Use this input: 
 * 11
 * 1 5 5 2 3 6 4 10 1 5 6
 *
 * Inversions: 17
 *
 * st.order_of_key({a[i],i}) gives the count of elements which are strictly less than a[i]
 * thus deducting this value from the size of set gives the number of elements which are strictly greater than a[i]
 * hence overall it is st.size()-st.order_of_key({a[i],i})
 *
 */
