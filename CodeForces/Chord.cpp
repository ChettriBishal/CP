#include<bits/stdc++.h>
using namespace std;
int getind(vector<string>g,string c) // to get the position of the notes from the vector
{
    int ind=find(g.begin(),g.end(),c)-g.begin();    
    return ind;
}
string kinds(int x,int y,int z) // to return the type of chord
{   
    int tone1,tone2;
    if(y<x) 
        tone1=y+12-x;
    else
        tone1=y-x;
    if(z<y)
        tone2=z+12-y;
    else
        tone2=z-y;
    if(tone1==4 and tone2==3) return "major";
    else if(tone1==3 and tone2==4) return "minor";
    else return "strange";
}
vector<string> bis(int x,int y,int z)
{
    vector<string>res(6); // 6 choices 3 X 2... permutations nPr  where n=3, r=2
    res[0]=kinds(x,y,z);
    res[1]=kinds(x,z,y);
    res[2]=kinds(y,x,z);
    res[3]=kinds(y,z,x);
    res[4]=kinds(z,x,y);
    res[5]=kinds(z,y,x);
    return res;
}
int main()
{
    vector<string> chords{"C","C#","D","D#","E","F","F#","G","G#","A","B","H"};
    string a,b,c;
    cin>>a>>b>>c;
    int x,y,z; // to store the positions of the notes
    x=(int) (getind(chords,a)+1)%12; 
    y=(int) (getind(chords,b)+1)%12; 
    z=(int) (getind(chords,c)+1)%12; 
    vector<string>res(6);
    res=bis(x,y,z);
    bool en=true; // if strange
    for(int i=0;i<6;i++)
    {   
        if(res[i]=="major" or res[i]=="minor"){ 
            cout<<res[i]<<"\n";
            en=false;   
            break;
        }
    }
    if(en)
        cout<<"strange"<<"\n";
    return 0;
}
