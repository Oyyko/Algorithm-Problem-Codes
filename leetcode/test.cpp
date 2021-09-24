#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

int abs1(int x)
{
    return x > 0 ? x : -x;
}

#include <cmath>

int main()
{
    int x{-2147483648};
    cout << x << endl; //-2147483648
    cout << -x;        //-2147483648
    //int [-2^31,2^31-1]
}