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
private:
    int change(string s)
    {
        int ans{};
        for (auto c : s)
        {
            ans *= 10;
            ans += c - '0';
        }
        return ans;
    }

public:
    bool areNumbersAscending(string s)
    {
        int last{-1};
        int now{-1};
        stringstream ss{s};
        string noww{};
        while (ss >> noww)
        {
            last = now;
            if (noww[0] > '9' || noww[0] < '0')
            {
                continue;
            }
            now = change(noww);
            if (now > last)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    string ss = "hello world 5 x 5"s;
    s.areNumbersAscending(ss);
}