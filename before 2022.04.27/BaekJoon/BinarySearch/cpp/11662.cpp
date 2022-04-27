//2021.12.10
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

struct point{
    double x, y;
}typedef point;

point a, b, c, d;
double lo = 0;
double hi = 100;
double ans;
point minho(double p){
    return {a.x + (b.x - a.x) * (p/100), a.y + (b.y - a.y) * (p/100)};
}
point kangho(double p){
    return {c.x + (d.x - c.x) * (p/100), c.y + (d.y - c.y) * (p/100)};
}

double dist(point p1, point p2){
    return sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2));
}

void ternarySearch(){
    ans = dist({10000,2}, {2,10000});
    while(hi - lo >= 1e-6){
        double p = (lo*2+hi)/3;
        double q = (lo+hi*2)/3;
        point p_m = minho(p);
        point p_k = kangho(p);
        point q_m = minho(q);
        point q_k = kangho(q);
        double dist1 = dist(p_m, p_k);
        double dist2 = dist(q_m, q_k);
        ans = min(ans, min(dist1, dist2));
        if(dist1 > dist2){
            lo = p;
        }
        else {
            hi = q;
        }
    }
}

int main(){
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    ternarySearch();
    cout.setf(ios::fixed);
	cout.precision(10);
    cout << ans;
}