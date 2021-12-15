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
    string defangIPaddr(string address)
    {
        string ans;
        for (const auto &x : address)
        {
            if (x != '.')
                ans.push_back(x);
            else
            {
                ans.push_back('[');
                ans.push_back('.');
                ans.push_back(']');
            }
        }
        return ans;
    }
};

int main()
{
}