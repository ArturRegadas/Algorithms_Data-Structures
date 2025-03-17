#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAXN (long long)1e5
using namespace std;

struct point{
    long long x, y;
};

point createPoint(long long a, long long b) {
    return {a, b};
}

struct line{
    long double m, b, x; 
    bool vertical;
};

line createLine(point a, point b){
    line ans;
    ans.vertical = a.x==b.x;
    ans.x = a.x;
    ans.m = (long double)(b.y-a.y)/(long double)(b.x - a.x);
    ans.b = a.y - ans.m*a.x;
    return ans;
} 
long double intersection(line a, line b){
    if(b.vertical)return b.x;
    if(a.m == b.m)return -1*1e9;
    return (b.b - a.b) / (a.m-b.m);
}

bool RayCasting(point a, point poligon[], long long n){
    bool ans = false;
    for(long long i=0;i<n;i++){
        point p1 = poligon[i];
        point p2 = poligon[(i+1)%n];

        if(a.y > min(p1.y, p2.y) && a.y <= max(p1.y, p2.y)){

            long double pointisectionPolygon = intersection(
                createLine(a, createPoint(a.x+1, a.y)),
                createLine(p1, p2));
            //cout<<long longersectionPolong long<<" "<<i<<"::\n";
            if(a.x >pointisectionPolygon){
                ans = !ans;
            }
        }
    }
    return ans;
}
int main(){
    point poligon[MAXN];
    long long x, y;
    scanf("%lld%lld", &x, &y);
    point p = createPoint(x, y);
    long long n;scanf("%lld", &n);


    for(int i =0;i<n;i++){
        scanf("%lld%lld", &x, &y);
        poligon[i] = createPoint(x, y);
    }
    
    bool ans =RayCasting(p, poligon, n);
    if(ans)printf("In");
    else printf("Out");
    return 0;
}