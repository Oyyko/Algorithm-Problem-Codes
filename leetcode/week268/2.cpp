#include <bits/stdc++.h>

using namespace std;

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
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int now_weizhi{-1};
        int now_shui{capacity};
        int n = plants.size();
        int ans{};
        for (int i = 0; i < n; ++i)
        {
            if (now_shui >= plants[i])
            {
                now_shui -= plants[i];
                ans++;
            }
            else
            {
                now_shui = capacity;
                now_shui -= plants[i];
                ans += i + i + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{7, 7, 7, 7, 7, 7, 7};
    cout << s.wateringPlants(v, 8);
}