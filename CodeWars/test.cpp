#include <iostream>

using namespace std;

int main()
{
    int a[100];
    for (auto &x : a)
    {
        x = 3;
    }
    for (auto x : a)
    {
        cout << x;
    }
}