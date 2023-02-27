#include <bits/stdc++.h>

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
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        map<int, int> mp1, mp2;
        set<int> id;
        for (auto &v : nums1)
        {
            mp1[v[0]] = v[1];
            id.insert(v[0]);
        }
        for (auto &v : nums2)
        {
            mp2[v[0]] = v[1];
            id.insert(v[0]);
        }
        vector<vector<int>> vvi;
        for (auto i : id)
        {
            vvi.push_back(vector<int>{i, mp1[i] + mp2[i]});
        }
        return vvi;
    }
};

int main()
{
}