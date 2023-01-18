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

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> pq;
        for (auto &x : nums)
        {
            pq.push(x);
        }
        using ll = long long;
        ll ans{};
        for (int i = 0; i < k; ++i)
        {
            int temp = pq.top();
            pq.pop();
            ans += temp;
            pq.push(upper_divide(temp, 3));
        }
        return ans;
    }
};

int main()
{
}