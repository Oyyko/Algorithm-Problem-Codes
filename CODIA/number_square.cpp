#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a1, a2, a3, maxx{-1};
    // because let a1'=a1+10, then all propoties will not be violated.
    // So the max of a1 is at least n-9.
    // if the max of a1 is less than n-9, let a1'=a1+10, then a1' will obey the given rules too.
    // the same logic can be used for a2 and a3
    for (a1 = n - 9; a1 <= n; ++a1)
    {
        for (a2 = n - 29; a2 <= n; ++a2)
        {
            for (a3 = n - 14; a3 <= n; ++a3)
            {
                if ((a1 + a2) % 2 == 0 && (a2 + a3) % 3 == 0 && (a1 + a2 + a3) % 5 == 0)
                {
                    maxx = max(maxx, a1 + a2 + a3);
                }
            }
        }
    }
    cout << maxx;
}