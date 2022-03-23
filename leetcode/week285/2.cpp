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

class Solution
{
public:
    int countCollisions(string directions)
    {
        int cnt{};
        int n = directions.size();
        int i = 0;
        while (i < n && directions[i] == 'L')
            i++;
        if (i == n)
            return 0;
        cnt += i;
        i = n - 1;
        while (i >= 0 && directions[i] == 'R')
            i--;
        cnt += n - i;
        cnt--;
        for (auto &x : directions)
            cnt += (x == 'S');
        return n - cnt;
    }
};

int main()
{
}