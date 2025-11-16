#include <utility>
#include <vector>
#include <iostream>

using namespace std;

struct Point{
    float x,y;
};

struct Line {
    float slope,intercept;
};

float get_average (const float& a, const float& b, const float& c, const float& d) {
    return (a+b+c+d)/4;
}

Line get_line_from_points(const Point& a, const Point& b) {
    float slope = (b.y-a.y)/(b.x-a.x);
    float intercept = (a.y - slope*a.x);
    return Line{slope, intercept};
}

Line get_bisector(const vector<Point>& square1, const vector<Point>& square2) {
    Point sq1_cent { get_average(square1[0].x, square1[1].x, square1[2].x, square1[3].x), 
                    get_average(square1[0].y, square1[1].y, square1[2].y, square1[3].y) };
    Point sq2_cent{get_average(square2[0].x, square2[1].x, square2[2].x, square2[3].x),
                   get_average(square2[0].y, square2[1].y, square2[2].y, square2[3].y)};

    return get_line_from_points(sq1_cent, sq2_cent);
}

int main(){
}