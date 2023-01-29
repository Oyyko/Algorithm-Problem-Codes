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
    bool makeStringsEqual(string s, string target)
    {
        int n = s.size();
        int cnt1{}, cnt2{};
        for (auto &c : s)
            cnt1 += c == '1';
        for (auto &c : target)
            cnt2 += c == '1';
        if (cnt1 == 0)
        {
            return cnt2 == 0;
        }
        if (cnt1 >= 1)
        {
            if (cnt2 == 0)
                return false;
            return true;
        }
        return false;
    }
};

int main()
{
}