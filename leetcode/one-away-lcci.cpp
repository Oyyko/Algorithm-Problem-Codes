#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    bool oneEditAway(const string &first, const string &second)
    {
        int n1 = first.size(), n2 = second.size();
        if (n2 - n1 == 1)
        {
            int i1 = 0, i2 = 0;
            while (i1 < n1 && i2 < n2)
            {
                if (second[i2] == first[i1])
                    i1++;
                i2++;
                if (i2 - i1 > 1)
                    return 0;
            }
            return 1;
        }
        else if (n2 == n1)
        {
            bool diff = false;
            for (int i = 0; i < n1; ++i)
            {
                if (first[i] != second[i])
                {
                    if (diff)
                    {
                        return 0;
                    }
                    diff = 1;
                }
            }
            return 1;
        }
        else if (n2 - n1 == -1)
        {
            return oneEditAway(second, first);
        }
        else
            return false;
    }
};

int main()
{
}