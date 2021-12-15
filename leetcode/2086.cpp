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
    int minimumBuckets(string street)
    {
        int n = street.size();
        if (n == 1)
            return street[0] == '.' ? 0 : -1;
        int ans{};
        if (street[0] == 'H')
            if (street[1] == 'H')
                return -1;
            else
                street[1] = 'T', ans++;
        for (int i = 1; i <= n - 2; ++i)
        {
            if (street[i] == 'H')
            {
                if (street[i - 1] == 'T')
                    continue;
                if (street[i + 1] == '.')
                {
                    street[i + 1] = 'T', ans++, i++;
                    continue;
                }
                if (street[i - 1] == '.')
                {
                    ans++;
                    continue;
                }
                return -1;
            }
        }
        if (street[n - 1] == 'H')
        {
            ans += (street[n - 2] == '.');
            if (street[n - 2] == 'H')
                return -1;
        }

        return ans;
    }
};

int main()
{
}