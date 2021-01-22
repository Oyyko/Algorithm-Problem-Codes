#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x;
    cin >> x;
    double gpa{};
    if (x >= 90)
        gpa = 4.0;
    else if (x >= 60)
    {
        gpa = 4.0 - (90 - x) * 0.1;
    }
    else
    {
        x = static_cast<int>(sqrt(x) * 10);
        gpa = 4.0 - (90 - x) * 0.1;
        if (x < 60)
            gpa = 0;
    }
    printf("%.1lf\n", gpa);
}