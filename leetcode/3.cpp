#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

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

int l(string s)
{
    unordered_set<char> occ;
    int l = 0;
    int r = 0;
    int ans{};
    for (; l < s.size(); ++l)
    {
        if (l != 0)
        {
            occ.erase(s[l - 1]);
        }
        while (r < s.size() && occ.count(s[r]) == 0)
        {
            occ.insert(s[r]);
            r++;
        }
        ans = max(ans, r - l);
    }
    return ans;
}

int main()
{
    cout << l("abcabcbb"s);
}