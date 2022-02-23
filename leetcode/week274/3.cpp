#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
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

class Solution
{
public:
    using LL = long long;
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(begin(asteroids), end(asteroids));
        LL now = mass;
        for (auto &x : asteroids)
        {
            if (now < x)
                return false;
            now += x;
            if (now > 100005)
                return true;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> v{4, 9, 23, 4};
    cout << s.asteroidsDestroyed(5, v);
}