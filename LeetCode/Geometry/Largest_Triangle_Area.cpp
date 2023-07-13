class Solution {
public:
    double getarea(double a, double b, double c){
        double s = (double)(a + b+ c)/2.00000;
        return sqrt(s*(s-a) * (s-b) * (s -c)); // heron's formula
    }
    double getdistance(vector<int> & a, vector<int> &b){
        double x1, y1;
        x1 = abs(a[0] - b[0]);
        y1 = abs(a[1] - b[1]);
        return sqrt(x1*x1 + y1* y1);
        
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double res = 0;
        for(int i=0;i<n;i++){
            for(int j= i+1;j<n;j++){
                for(int k= j+1;k<n;k++){
                    double a, b,c;
                    a = getdistance(points[i],points[j]);
                    b = getdistance(points[i],points[k]);
                    c = getdistance(points[j], points[k]);
                    res = max(res, getarea(a,b,c));
                }
            }
        }
        return res;
    }
};
