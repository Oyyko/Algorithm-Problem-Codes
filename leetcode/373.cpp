#include <iostream>
#include <vector>
#include <bits/stdc++.h>

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

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int rows = nums1.size();
        int cols = nums2.size();
        vector<vector<int>> ans;
        if (rows == 0 || cols == 0)
        {
            return ans;
        }
        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b)
        { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < rows; i++)
        {
            pq.emplace(i, 0);
        }
        while (k > 0 && !pq.empty())
        {
            k--;
            pair<int, int> temp = pq.top();
            pq.pop();
            if (temp.second + 1 < cols)
            {
                pq.emplace(temp.first, temp.second + 1); //列+1
            }
            vector<int> item;
            item.push_back(nums1[temp.first]);
            item.push_back(nums2[temp.second]);
            ans.push_back(item);
        }
        ​ return ans;
    }
};

int main()
{
}