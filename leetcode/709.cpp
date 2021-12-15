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
    string toLowerCase(string s)
    {
        for (auto &x : s)
        {
            if ('A' <= x && x <= 'Z')
            {
                x += (-'A' + 'a');
            }
        }
        return s;
    }
};

int main()
{
}