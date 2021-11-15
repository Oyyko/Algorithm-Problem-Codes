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

int nums[3000005];
int ans[3000005];

int main()
{
    int n;
    vector<int> s{};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &nums[i]);
    }
    s.push_back(n);
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && s.back() < n && nums[i] >= nums[s.back()])
        {
            s.pop_back();
        }
        ans[i] = s.back();
        s.push_back(i);
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", ans[i] == n ? 0 : ans[i] + 1);
    }
}