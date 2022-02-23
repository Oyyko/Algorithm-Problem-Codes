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
    string reversePrefix(string word, char ch)
    {
        string ans;
        bool finding = 1;
        stack<char> s;
        for (const auto &x : word)
        {
            if (finding)
            {
                s.push(x);
                if (x == ch)
                {
                    finding = 0;
                    while (!s.empty())
                    {
                        ans.push_back(s.top());
                        s.pop();
                    }
                }
            }
            else
            {
                ans.push_back(x);
            }
        }
        if (finding)
            return word;
        return ans;
    }
};

int main()
{
}