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
    int val(char c)
    {
        return c - 'a' + 1;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        int n = s.size();
        power %= modulo;
        int startindex = n - k;
        using LL = long long;
        LL hash_now{};
        LL pow_now{1};
        for (int i = startindex; i <= startindex + k - 1; ++i)
        {
            hash_now += val(s[i]) * pow_now;
            pow_now *= power;
            pow_now %= modulo;
            hash_now %= modulo;
        }
        int ans;
        // cout << s.substr(startindex, k) << " " << hash_now << endl;

        if (hash_now == hashValue)
            ans = startindex;
        while (startindex != 0)
        {
            startindex--;
            hash_now *= power;
            hash_now += val(s[startindex]);
            hash_now -= val(s[startindex + k]) * pow_now;
            while (hash_now < 0)
                hash_now += modulo;
            hash_now %= modulo;
            if (hash_now == hashValue)
                ans = startindex;
            // cout << s.substr(startindex, k) << " " << hash_now << endl;
        }
        return s.substr(ans, k);
    }
};

int main()
{
    Solution s;
    cout << s.subStrHash("leetcode", 7, 20, 2, 0);
}