#include <iostream>

using namespace std;

bool is_equal(double x, double y)
{
    if ((x - y) <= 1e-9 && (y - x) <= 1e-9)
    {
        return 1;
    }
    return 0;
}

bool is_equal(int x, int y)
{
    return x == y;
}

/*

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while (!a && !b && !c && !d == 0)
    {

        cin >> a >> b >> c >> d;
    }
}

*/

int main()
{
    
}