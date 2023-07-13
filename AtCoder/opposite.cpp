/*
10-Apr-21 5:14:59 PM
*/
#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238
pair<double,double> rotate(double x,double y,double rad)
{
    pair<double,double>a;
    a.first=cos(rad)*x-sin(rad)*y;
    a.second=sin(rad)*x+cos(rad)*y;
    return a;
}
int main()
{
    int n;
    cin>>n;
    int x0,y0,xh,yh;
    cin>>x0>>y0>>xh>>yh;
    double qx,qy;// represents the center of the circle which inscribes the n-gon
    qx=(x0+xh)/2.0;
    qy=(y0+yh)/2.0;
    pair<double,double>res=rotate(x0-qx,y0-qy,2*PI/n);
    cout<<fixed<<setprecision(8);
    cout<<res.first+qx<<" "<<res.second+qy<<endl;
    return 0;

}
/* Let Q(qx,qy) and A(x0,y0)                         __>
 * (x0-qx) (and (y0-qy)) ensures that this is vector QA
 * then use the formula given to rotate this vector QA by angle 2*PI/n then find the new coordinates
 * Finally in the answer we want with respect to origin based reference so we add qx and qy
 * Like suppose the measurement with respect to 4 is 2 units but with respect to origin it is 4+2=6
 * 0  1  2  3  4  5  6  7  8
 *             |  1  2 ---->2 units wrt 4 but 6 units wrt 0
 */
