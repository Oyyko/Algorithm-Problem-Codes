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
    int minimumTime(string s)
    {
        int ans{};
        if (s == "")
            return 0;
        int last_ll = 0;
        int last_rr = s.size() - 1;
        int k{};
        
    }
};

int main()
{
}