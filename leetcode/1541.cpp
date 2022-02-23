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
    int minInsertions(string s)
    {
        int lbraket{};
        int ans{};
        int n = s.size();
        for (int i{}; i < n; ++i)
        {
            const char &x = s[i];
            if (x == '(')
                lbraket++;
            else
            {
                if (lbraket > 0)
                    lbraket--;
                else
                    ans++;
                if (i != n - 1 && s[i + 1] == ')')
                    i++;
                else
                    ans++;
            }
            ans += lbraket * 2;
        }
        return ans;
    }
};

int main()
{
}