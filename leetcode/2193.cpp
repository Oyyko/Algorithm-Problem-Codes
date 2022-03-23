#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
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
    int minMovesToMakePalindrome(string s)
    {
        int n = s.size(), ans = 0;
        for (int i = 0, j = n - 1; i < j; ++i)
        {
            for (int k = j; i != k; --k)
            {
                if (s[i] == s[k])
                {
                    for (; k < j; ++k)
                        swap(s[k], s[k + 1]), ans++;
                    j--;
                    goto OK;
                }
            }
            ans += n / 2 - i;
        OK:
            continue;
        }
        return ans;
    }
};

int main()
{
}