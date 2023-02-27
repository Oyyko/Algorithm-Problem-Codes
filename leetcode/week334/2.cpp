#include <bits/stdc++.h>

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
    vector<int> divisibilityArray(string word, int m)
    {
        int n = word.size();
        vector<int> ans(n, 0);
        using ll = long long;
        ll tmp{};
        int i{};
        for (auto c : word)
        {
            tmp *= 10;
            tmp += c - '0';
            tmp %= m;
            if (tmp == 0)
                ans[i++] = 1;
            else
                ans[i++] = 0;
        }
        return ans;
    }
};

int main()
{
}