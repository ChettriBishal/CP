#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int>l{4,5,1,2,7,11,9,3};
    cout<<"List: ";
    for(auto it=l.begin();it!=l.end();it++)
        cout<<(*it)<<" ";
    cout<<endl<<endl;
    cout<<"Sorting the list\n";
    l.sort();
    for(auto val:l)
        cout<<val<<" ";
    cout<<endl<<endl;
    cout<<"Reversing the list\n";
    l.reverse();
    for(auto val:l)
        cout<<val<<" ";
    cout<<endl<<endl;

    l.push_back(7); // inserts at the tail
    cout<<"After pushing at tail\n";
    cout<<"List: ";
    for(auto val: l)
        cout<<val<<" ";
    cout<<endl<<endl;
    l.pop_front(); // removing from the head
    cout<<"After removing from head\n";
    for(auto val:l)
        cout<<val<<" ";
    cout<<endl<<endl;
    cout<<"Enter a value you want to remove from the list\n";
    int key; cin>>key;
    l.remove(key);
    cout<<"List now\n";
    for(auto k: l)
        cout<<k<<" ";
    cout<<endl<<endl;
    cout<<"Enter the position of element to erase\n"; // 1 based index
    int n; cin>>n;n--;
    auto it=l.begin();
    while(n--)
        it++;
    l.erase(it);
    cout<<"List after erasing\n";
    for(auto k:l)
        cout<<k<<" ";
    cout<<endl<<endl;
    cout<<"Enter the position where you want to insert the element and the element itself\n";
    cin>>n;n--; cin>>key;
    it=l.begin();
    while(n--)
        it++;
    l.insert(it,key);
    cout<<"List after inserting\n";
    for(auto k:l)
        cout<<k<<" ";
    cout<<endl<<endl;
    cout<<endl;
    
    return 0;

}
/*
 * List here signifies doubly linked list
 * Useful for insert and delete from middle or front at O(1) complexity
 */
