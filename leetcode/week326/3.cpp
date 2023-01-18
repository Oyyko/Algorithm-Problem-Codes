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
    int minimumPartition(string s, int k)
    {
        int ans{};
        long long now_num{};
        for (auto x : s)
        {
            now_num *= 10;
            now_num += x - '0';
            if (now_num < 10 && now_num > k)
            {
                return -1;
            }
            if (now_num > k)
            {
                ans++;
                now_num = x - '0';
            }
            if (now_num < 10 && now_num > k)
            {
                return -1;
            }
        }
        ans++;
        return ans;
    }
};

int main()
{
}