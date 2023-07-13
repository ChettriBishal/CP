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
    ordered_set st;
    st.insert(15);
    st.insert(10);
    st.insert(1);
    st.insert(4);
    st.insert(3);
    
    for(auto i=st.begin();i!=st.end();i++)
        cout<<*i<<" "<<endl;
    
    cout<<endl;

    for(int i=0;i<st.size();i++) // to know at a particular index which value do we have
        cout<< i <<" "<<*st.find_by_order(i)<<"\n"; 
    
    cout<<"Order of "<<15<<" "<<st.order_of_key(15)<<endl;
    return 0;
}
