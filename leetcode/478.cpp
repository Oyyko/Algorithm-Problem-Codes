#include <iostream>
#include <random>
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
#include <random>
#include <chrono>

class Solution
{
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;

public:
    Solution(double radius, double x_center, double y_center) : dis(-radius, radius), xc(x_center), yc(y_center), r(radius) {}

    vector<double> randPoint()
    {
        while (true)
        {
            double x = dis(gen), y = dis(gen);
            if (x * x + y * y <= r * r)
            {
                return {xc + x, yc + y};
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main()
{
}