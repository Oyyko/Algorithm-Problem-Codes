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
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        heaters.insert(heaters.begin(), INT_MIN);
        heaters.push_back(INT_MAX);

        long long r = 0;
        int n = heaters.size();
        int cur = 0;

        for (int i = 0; i < houses.size(); i++)
        {
            while (cur < n + 2)
            {
                if (heaters[cur] >= houses[i])
                    break;
                cur++;
            }
            r = max(r, min((long long)heaters[cur] - houses[i], (long long)houses[i] - heaters[cur - 1]));
        }
        return r;
    }
};

int main()
{
}