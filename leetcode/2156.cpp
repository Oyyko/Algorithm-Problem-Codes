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
    using ll = long long;
    int pow(int ori, int pow, int m)
    {
        ll ans = 1, tmp = ori;
        for (int i = 0; i < 32; ++i)
        {
            if (pow & (1 << i))
            {
                ans *= tmp;
                ans %= m;
            }
            tmp *= tmp;
            tmp %= m;
        }
        return ans;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        power %= modulo;
        int pk = pow(power, k - 1, modulo);
        // cout << "PK" << pk << endl;
        int n = s.size();
        ll tmp{};
        int ans{};
        for (int i = n - 1; i >= n - k; --i)
        {
            tmp *= power;
            tmp += s[i] - 'a' + 1;
            tmp %= modulo;
        }
        if (tmp == hashValue)
            ans = n - k;
        // cout << s.substr(n - k, k) << "  " << tmp << endl;
        for (int i = n - 1 - k; i >= 0; --i)
        {
            tmp -= pk * (s[i + k] - 'a' + 1ll);
            while (tmp < 0)
                tmp += modulo;
            tmp *= power;
            tmp += s[i] - 'a' + 1ll;
            tmp %= modulo;
            // cout << s.substr(i, k) << "  " << tmp << endl;
            if (tmp == hashValue)
                ans = i;
        }
        return s.substr(ans, k);
    }
};

int main()
{
    Solution s;
    cout << s.subStrHash("leetcode", 7, 20, 2, 0);
}