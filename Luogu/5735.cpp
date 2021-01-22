#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    double x;
    double y;
};

inline double squ(double x)
{
    return x * x;
}

double dis(Point a, Point b)
{
    return sqrt(squ(a.x - b.x) + squ(a.y - b.y));
}

int main()
{
    Point a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    printf("%.2lf", dis(a, b) + dis(b, c) + dis(c, a));
}