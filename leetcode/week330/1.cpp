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
    int distinctIntegers(int n)
    {
        set<int> s;
        s.insert(n);
        for (int i = 0; i <= 1000000000; ++i)
        {
            int old = s.size();
            for (auto x : s)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (x % j == 1)
                    {
                        s.insert(j);
                    }
                }
            }
            if (s.size() == old)
                return old;
        }
        return s.size();
    }
};

int main()
{
}