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
    int removePalindromeSub(string s)
    {
        auto itr1 = s.begin();
        auto itr2 = s.end() - 1;
        while (itr1 < itr2)
        {
            if (*itr1 != *itr2)
            {
                return 2;
            }
            itr1++;
            itr2--;
        }
        return 1;
    }
};

int main()
{
}