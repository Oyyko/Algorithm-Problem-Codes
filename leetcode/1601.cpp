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
    int maximumRequests(int n, vector<vector<int>> &requests)
    {

        int m = requests.size();
        int set_size = (1 << m);
        int ans{};
        int cnt{};
        for (int i{}; i < set_size; ++i)
        {
            cnt = 0;
            vector<int> in(n, 0);
            for (int j{}; j < m; ++j)
            {
                if ((1 << j) & (i))
                {
                    in[requests[j][0]]--;
                    in[requests[j][1]]++;
                    cnt++;
                }
            }
            for (int ii{}; ii < n || (ans = max(ans, cnt), 0); ++ii)
            {
                if (in[ii] != 0)
                    break;
            }
        }
        return ans;
    }
};

int main()
{
}