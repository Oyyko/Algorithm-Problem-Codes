#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
using namespace std;

using LL = long long;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a << " ";
    }
    cout << endl;
}

class Solution
{
public:
    bool isSameAfterReversals(int num)
    {
        if (num == 0)
        {
            return true;
        }
        if (num % 10 == 0)
        {
            return false;
        }
        return true;
    }
};

int main()
{
}