#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string ans{};
        for (auto i = num.begin() + 1; i < num.end(); ++i)
        {
            if (i[-1] <= i[0])
            {
                ans.push_back(i[-1]);
                continue;
            }
            if (k)
            {
                k--;
            }
            else
            {
                ans.push_back(i[-1]);
            }
        }
        return ans.substr(0, num.size() - k);
    }
};

int main()
{
}