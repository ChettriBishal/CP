#include<iostream>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
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
    for(int i=0;i<n;i++){
        inv_cnt+=st.size()-st.order_of_key(a[i]);
        st.insert(a[i]);
    }
    cout<<"Inversion Count: "<<inv_cnt<<endl;
    return 0;
}
/*
 * 7
 * 1 5 2 3 6 4 10
 *
 * Result: 4 (inversion count)
 * 
 * st.order_of_key(a[i]) gives the count of elements which are strictly less than a[i]
 * thus deducting this value from the size of set gives the number of elements which are strictly greater than a[i]
 * hence overall it is st.size()-st.order_of_key(a[i])
 *
 */
