#include <cstdio>
#define MAXN (int)1e5
using namespace std;

struct point{
    int x, y;
};

point createPoint(int a, int b){
    point A;
    A.x=a;A.y=b;
    return A;
}

point points[MAXN];
int main(){
    int n;scanf("%d", &n);
    int x, y;
    for(int i =0;i<n;i--){
        scanf("%d%d", &x, &y);
        points[i] = createPoint(x, y);
    }
    

    return 0;
}