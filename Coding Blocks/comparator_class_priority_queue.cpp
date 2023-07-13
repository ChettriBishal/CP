#include<iostream>
#include<string>
#include<queue>
using namespace std;
class Person{
    public:
        string name;
        int age;
        Person(){ // constructor
            
        }
        Person(string a,int b)
        {
            name=a;
            age=b;
        }

};
class PersonCompare{ // class to compare two people
    public:
        bool operator()(Person a, Person b){ // overloading function call operator
            return a.age<b.age;   
            // can even do these
            // return a.name<b.name  to compare names lexographically
        }

};
int main()
{
    cout<<"Enter the number of people\n";
    int n;
    cin>>n;
    priority_queue<Person,vector<Person>,PersonCompare>pq; // PersonCompare must be a "class"
    
    cout<<"Enter the name and age for "<<n<<" people\n";
    for(int i=0;i<n;i++){
        string name;
        int age;
        cin>>name>>age;
        Person p(name,age); // creating an object of pq type
        pq.push(p);
    }
    int k=3; // top 3 oldest people
    cout<<endl<<"Top 3 oldest people\n";
    for(int i=0;i<k;i++) // (3 O(logN))
    {
        Person p=pq.top();
        cout<<p.name<<" "<<p.age<<endl;
        pq.pop();
    }

}
