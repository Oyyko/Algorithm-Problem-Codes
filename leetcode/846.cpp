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
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize)
            return false;
        if (groupSize == 1)
            return true;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> cnt;
        for (const auto &x : hand)
        {
            cnt[x]++;
            pq.push(x);
        }
        while (!pq.empty())
        {
            auto tmp = pq.top();
            pq.pop();
            if (cnt[tmp] == 0)
                continue;
            for (int i = tmp, _ = tmp + groupSize - 1; i <= _; ++i)
            {
                if (cnt[i] > 0)
                    cnt[i]--;
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 2, 3, 6, 2, 3, 4, 7, 8};
    cout << s.isNStraightHand(v, 3);
}