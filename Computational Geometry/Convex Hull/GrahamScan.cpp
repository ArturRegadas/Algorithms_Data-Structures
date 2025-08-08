#include <bits/stdc++.h>
#define MAXN 1e9
#define pb push_back
#define lb long double
using namespace std;

struct point{
    int x, y;
    point() : x(0), y(0) {}  
    point(int a, int b) : x(a), y(b) {}
};

struct Vector{
    int x, y;
    Vector() : x(0), y(0) {}  
    Vector(int a, int b) : x(a), y(b) {}
};

bool comparation(pair<long double, point> a, pair<long double, point> b) {
    return a.first > b.first;
}


point getMin(vector<point>& points){
    int minValue = MAXN;
    int ans = 0;
    for(int i =0;i<points.size();i++){
        if(points[i].x<minValue){
            ans = i;
            minValue = points[i].x; 
        }
    }
    point minus = points[ans];
    points.erase(points.begin()+ans);
    return minus;
}

lb getAngle(const point a, const point b, const point c) {
    Vector BA(a.x-b.x, a.y-b.y);
    Vector BC(c.x-b.x, c.y-b.y);
    lb prodEscalar = BA.x*BC.x + BA.y*BC.y;
    lb cos = prodEscalar / (sqrt(BA.x * BA.x + BA.y * BA.y)*(BC.x * BC.x + BC.y * BC.y));
    return acos(cos) * 180.0L / M_PI; 
}



vector<pair<lb, point>> angleForPoint(point base, vector<point>points){
    vector<pair<lb, point>> ans(points.size());
    point aux (base.x, base.y+1);
    for(int i =0;i<points.size();i++)ans[i] = {getAngle(points[i], base, aux), points[i]};
    return ans;

}

vector<point> grahamScan(vector<point> points){


    //primeiro passo é pegar o ponto que é garatido que estara no ConvexHull
    //no caso usarei o poligono mais a esquerda
    point base = getMin(points);
    vector<point> ConvexHull = {base};
    //o segundo passo é ordenar os pontos baseado no angulo deles para o ponto base
    vector<pair<lb, point>> AnglePoint = angleForPoint(base, points);
    sort(AnglePoint.begin(), AnglePoint.end(), comparation);


    //se o angulo do atual for maior que o angulo anterior, substiui
    //se nao apenas incrementa ao ConvexHull
    for(pair<lb, point> current : AnglePoint){
        while(ConvexHull.size()>2 && 
        getAngle(current.second, ConvexHull[ConvexHull.size()-2], ConvexHull[ConvexHull.size()-3])>
        getAngle(ConvexHull.back(), ConvexHull[ConvexHull.size()-2],ConvexHull[ConvexHull.size()-3])){
            ConvexHull.pop_back();
        }
        ConvexHull.pb(current.second);
    }
    return ConvexHull;
}

int main(){

    int qtPoints, ix, iy;
    scanf("%d", &qtPoints);
    vector<point> points(qtPoints);
    for(int i =0;i<qtPoints;i++){
        scanf("%d%d", &ix, &iy);
        points[i] = point(ix, iy);
    }
    vector<point> ConvexHull = grahamScan(points);
    for(point i : ConvexHull){
        printf("%d %d\n", i.x, i.y);
    }
    return 0;
}