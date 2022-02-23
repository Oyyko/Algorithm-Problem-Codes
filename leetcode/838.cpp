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
    string pushDominoes(string dominoes)
    {
        int last{0}; // 0 for . || 1 for L  || 2 for R
        string ans{};
        int cnt{};
        for (auto &x : dominoes)
        {

            if (last == 0)
            {
                if (x == '.')
                    cnt++;
                else if (x == 'L')
                {
                    while (cnt)
                    {
                        ans.push_back('L');
                        cnt--;
                    }
                    last = 1;
                }
                else if (x == 'R')
                {
                    while (cnt)
                    {
                        ans.push_back('.');
                        cnt--;
                    }
                    last = 2;
                }
            }
            else if (last == 1)
            {
                if (x == '.')
                {
                    cnt++;
                }
                else if (x == 'L')
                {
                    while (cnt)
                    {
                        cnt--;
                        ans.push_back('L');
                    }
                    last = 1;
                }
                else if (x == 'R')
                {
                    last = 2;
                    while (cnt)
                    {
                        cnt--;
                        ans.push_back('.');
                    }
                }
            }
            else if (last == 2)
            {
                if (x == '.')
                {
                    cnt++;
                }
                else if (x == 'L')
                {
                    int half = cnt / 2;
                    for (int i = 1; i <= half; ++i)
                    {
                        ans.push_back('R');
                    }
                    if (cnt % 2)
                    {
                        ans.push_back('.');
                    }
                    for (int i = 1; i <= half; ++i)
                    {
                        ans.push_back('L');
                    }
                    cnt = 0;
                    last = 1;
                }
                else if (x == 'R')
                {
                    while (cnt)
                    {
                        cnt--;
                        ans.push_back('R');
                    }
                }
            }
            if (x != '.')
            {
                ans.push_back(x);
            }
        }
        if (last == 1 || last == 0)
        {
            while (cnt)
            {
                cnt--;
                ans.push_back('.');
            }
        }
        else if (last == 2)
        {
            while (cnt)
            {
                cnt--;
                ans.push_back('R');
            }
        }
        return ans;
    }
};

int main()
{
}