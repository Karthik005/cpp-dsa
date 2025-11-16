#include <iostream>
#include <utility>
#include <exception>
#include <cmath>

using namespace std;

struct point {
    float x;
    float y;
};

typedef pair<point,point> Lseg;

void get_slope_intercept(Lseg seg, float& slope, float& inter) {
    slope = (seg.first.y - seg.second.y) / (seg.first.x - seg.second.x);
    inter = seg.first.y - (slope * seg.first.x);
}

point get_intersection (Lseg seg1, Lseg seg2) {
    float slope1, inter1, slope2, inter2;
    get_slope_intercept(seg1, slope1, inter1);
    get_slope_intercept(seg2, slope2, inter2);
    if (slope1 == slope2) { throw invalid_argument("parallel lines");}
    cout << slope2 << " " << inter2 << endl;
    float x_val = (inter1 - inter2) / (slope2 - slope1);

    if (x_val > max<float>(seg1.second.x, seg2.second.x) ||
        x_val < min<float>(seg1.first.x, seg2.first.x)) {
        throw out_of_range("Intersection point out of range");
    }

    float y_val = (slope1 * x_val) + inter1;
    return point{x_val, y_val};
}

int main() {
    Lseg seg1 {
        {2,2},
        {7,7}
    };

    Lseg seg2 {
        {2, 10},
        {10, 1}
    };

    point inter = get_intersection(seg1, seg2);

    cout << "(" << inter.x << "," << inter.y << ")" <<endl;
}
