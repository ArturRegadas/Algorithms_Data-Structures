#include <bits/stdc++.h>
#define lb long double
using namespace std;

struct point{
    int x,y;
    point(int a, int b): x(a), y(b){};
};

lb shoelace(vector<point> points){
    int size = points.size();
    lb ans = 0;
    for(int i =0;i<size;i++){
        point point1 = points[i];
        point point2 = points[(i+1)%size];
        ans+=point1.x * point2.y - point1.y * point2.x;
    }
    return abs(ans)/2;
}


int main(){
    int qtPoints, x, y;
    scanf("%d", &qtPoints);
    vector<point> points(qtPoints);
    for(int i =0;i<qtPoints;i++){
        scanf("%d%d", &x, &y);
        points[i]=point(x, y);
    }
    lb Area = shoelace(points);
    printf("%Lb\n", Area);

    return 0;
}