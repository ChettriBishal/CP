#include<iostream>
#include<stack>
using namespace std;
void Reverse(string &s)
{
    stack<char>bis;
    for(int i=0;i<(int)s.length();i++)
        bis.push(s[i]);
    for(int i=0;i<(int)s.length();i++)
    {
        s[i]=bis.top(); // last element comes first now
        bis.pop();
    }
    // Time complexity is O(n)
    // Space complexity is also O(n)
}
int main()
{
    string s;
    cout<<"Enter a string to reverse:\n";
    cin>>s;
    Reverse(s);
    cout<<"String now: "<<s<<endl;
    return 0;
}
