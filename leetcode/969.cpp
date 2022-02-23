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
    int max_index(vector<int> &arr, int k)
    {
        int maxi{-1};
        int maxx{INT_MIN};
        for (int i{}; i <= k; ++i)
        {
            if (arr[i] > maxx)
            {
                maxx = arr[i];
                maxi = i;
            }
        }
        return maxi;
    }
    void reverse(vector<int> &arr, int k)
    {
        int l{};
        int r{k};
        while (r > l)
        {
            swap(arr[l], arr[r]);
            l++, r--;
        }
    }
    vector<int> pancakeSort(vector<int> &arr)
    {
        vector<int> ans{};
        int n = arr.size();
        int r = n - 1;
        while (r >= 1)
        {
            int maxi = max_index(arr, r);
            if (maxi != r)
            {
                if (maxi != 0)
                {
                    ans.push_back(maxi + 1);
                    reverse(arr, maxi);
                }
                reverse(arr, r);
                ans.push_back(r + 1);
            }
            r--;
        }
        return ans;
    }
};

int main()
{
}