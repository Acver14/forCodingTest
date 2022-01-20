//2021.08.12
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point{
public:
    int x;
    int y;
};

bool compare(Point a, Point b){
    if(a.y > b.y) return false;
    else if(a.y == b.y) {
        if(a.x > b.x) return false;
        else return true;
    }
    else return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<Point> point(n);
    for(int i = 0; i < n; i++){
        cin >> point[i].x >> point[i].y;
    }

    sort(point.begin(), point.end(), compare);

    for(const Point &item: point){
        cout << item.x << ' ' << item.y << '\n';
    }
}