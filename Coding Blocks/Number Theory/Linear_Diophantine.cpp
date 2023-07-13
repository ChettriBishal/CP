#include<iostream>
using namespace std;
int extgcd(int a,int b,int &x,int &y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int hcf=extgcd(b,a%b,x1,y1);

    x=y1;
    y=x1-(a/b)*y1;
    return hcf;
}

int main()
{
    int a,b,c;
    cout<<"ax + by =c\n";
    cout<<"Enter the values for a, b and c:\n";
    cin>>a>>b>>c;
    cout<<"\nYour equation\n";
    printf("%d x + %d y = %d\n\n",a,b,c);
    
    int xo,yo,k; // k*gcd(a,b)=c....
    int g=extgcd(a,b,xo,yo);
    
    printf("GCD(%d, %d) = %d\n\n",a,b,g);
    cout<<"Solution for gcd\n";
    printf("%d * %d  +  %d * %d = %d\n\n",a,xo,b,yo,g);

    if(c%g!=0){
        cout<<"NO integral solution possible\n";
    }
    else{
        k=c/g;
        cout<<"k= "<<k<<endl<<endl;
        cout<<"Primary solution\n";
        
        int x,y;
        x=xo*k;
        y=yo*k;
        
        printf("%d * %d + %d * %d   = %d * %d \n",a,x,b,y,k,g);
        cout<<endl<<"Other solutions\n";
        
        for(int i=1;i<=10;i++){
            int x1, y1;
            
            x1=x+(b/g)*i;
            y1=y-(a/g)*i;

            printf("%d * %d  +  %d * %d   = %d \n",a,x1,b,y1,c);
        }
        cout<<"\n...infinitely more solutions\n";
    }
    
    return 0;
}
// xo and yo are solutions when RHS is only gcd(a,b)
// x =k* xo and y= k* yo are the actual solutions when RHS is k* gcd(a,b)
