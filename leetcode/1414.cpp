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
private:
    using LL = long long;
    LL fib[60];
    constexpr static int m{50};

public:
    int findMinFibonacciNumbers(int k)
    {
        fib[1] = fib[2] = 1;
        for (int i{3}; i <= m; ++i)
            fib[i] = fib[i - 1] + fib[i - 2];
        int cnt{};
        int j{m};
        while (k)
        {
            while (fib[j] > k)
            {
                j--;
            }
            k -= fib[j];
            cnt++;
            j = m;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
}