#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Student{
public:
    string name;
    string roll;
    Student(string name,string roll)
    {
        this->name=name;
        this->roll=roll;
    }
    // this is to handle collisions 
    bool operator==(const Student &s)const // == overloaded // compare two students on the basis of roll no
    {
        return roll==s.roll; 
    }
    /*
     * roll is roll no of object which we are trying to search in table. whereas s.roll is roll no of object where
     * we are present during search .
     */
};

/*
 * here we are simply giving definition of hash function, i,e on what criteria we should hash the student object.
 * in this case we are taking legnth of name as hasing criteria
*/

class hashfunc{ // hashing on the basis of length of string 
public:
    size_t operator()(const Student &s) const{
        return s.name.length();    
    }

};
int main()
{
    unordered_map<Student,int,hashfunc> st; // mapping student to his marks
    Student s1("Gennady","01");
    Student s2("Errichto","011");
    Student s3("Petr","021");
    Student s4("Petr","870");
    
    // add student marks to hashmap
    st[s1]=99; 
    st[s2]=98;
    st[s3]=97;
    st[s4]=92;

    // iterate over all students
    for(auto k:st)
        cout<<k.first.name<<" "<<k.first.roll<<" Marks: "<<k.second<<endl;

    
}
/*
 * compiler doesn't know how to compare two student objects, so its user responsibiltiy to define explicitly how to compare
 * them , that is why we are overloading == operator .
 *
 * at the time of searching, comparison between two students will be required so there == (overloaded function) will be
 * used.
 *
 * when we need to check whether particular student present or not in the map then at that time, comparison is
 * required between student object we are looking and available student object present in map.
 *
 */


