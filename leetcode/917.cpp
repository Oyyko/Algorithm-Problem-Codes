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
    string reverseOnlyLetters(string s)
    {
        auto l = s.begin();
        auto r = s.end() - 1;
        while (l != r)
        {
            while (l != r && !isalpha(*l))
            {
                l++;
            }
            while (l != r && !isalpha(*r))
            {
                r--;
            }
            if (l == r)
                break;
            swap(*l, *r);
            l++, r--;
            if (l == r + 1)
            {
                break;
            }
        }
        return s;
    }
};

int main()
{
}