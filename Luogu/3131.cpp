#include <iostream>

using namespace std;

const int n_max = 50010;

int sum[n_max];

int first[7], last[7];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> sum[i];
        sum[i] = (sum[i] + sum[i - 1]) % 7;
    }
    for (int i = n; i >= 1; --i)
    {
        first[sum[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        last[sum[i]] = i;
    }
    int ans = -1;
    for (int i = 0; i < 7; ++i)
    {
        ans = last[i] - first[i] > ans ? last[i] - first[i] : ans;
    }
    cout << ans << endl;
}