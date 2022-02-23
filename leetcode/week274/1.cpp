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
    bool checkString(string s)
    {
        int a_last{-1};
        int b_first{-1};
        bool b_yes{false};
        for (int i{}; i < s.size(); ++i)
        {
            if (s[i] == 'a')
                a_last = i;
            if (b_yes == false && s[i] == 'b')
                b_first = i, b_yes = 1;
        }
        if (a_last == -1 || b_first == -1)
            return true;
        if (a_last < b_first)
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.checkString("bbb");
}