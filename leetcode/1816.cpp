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
    string truncateSentence(string s, int k)
    {
        int i{};
        for (int _ = s.size(); i < _; i++)
        {
            auto x = s[i];
            if (x == ' ')
                k--;
            if (k == 0)
                break;
        }
        return s.substr(0, i - 1);
    }
};

int main()
{
}