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
    int repeatedStringMatch(string a, string b)
    {
        string s{a};
        while (s.size() <= b.size())
        {
            s += a;
        }
        s += a;
        auto fd = s.find(b);
        if (fd == string::npos)
            return -1;
        auto ceil1 = [](int a, int b)
        { return (a - 1) / b + 1; };
        return ceil1(b.size() + fd, a.size());
    }
};

int main()
{
}