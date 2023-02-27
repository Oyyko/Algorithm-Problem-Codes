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
    using ll = long long;
    ll chuan(int a, int b)
    {
        int aa = 1;
        while (aa <= b)
        {
            aa *= 10;
        }
        a *= aa;
        a += b;
        return a;
    }
    long long findTheArrayConcVal(vector<int> &nums)
    {
        auto b = nums.begin();
        auto e = nums.end() - 1;
        ll ans{};
        while (b != e)
        {
            // cout << chuan(*b, *e) << endl;

            ans += chuan(*b, *e);
            auto old_b = b;
            b++;
            e--;
            if (e == old_b)
                break;
        }
        if (b == e)
            ans += *b;
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 78, 27, 48, 14, 86, 79, 68, 77, 20, 57, 21, 18, 67, 5, 51, 70, 85, 47, 56, 22, 79, 41, 8, 39, 81, 59, 74, 14, 45, 49, 15, 10, 28};
    vector<int> v1{2};
    cout << s.findTheArrayConcVal(v) << endl;
    cout << s.findTheArrayConcVal(v1) << endl;
}