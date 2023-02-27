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
    int minOperations(int n)
    {
        // cout << n << endl;
        int ans{};
        vector<int> v;
        while (n)
        {
            v.push_back(n % 2);
            n /= 2;
        }
        int b{}, e{};
        int s = v.size();
        vector<int> length(s, 0);
        while (b != s)
        {
            int color = v[b];
            while (e != s && v[e] == color)
            {
                e++;
            }
            if (color == 1)
            {
                if (e - b == 1)
                    ans++;
                if (e - b >= 2)
                    ans += 2;
                length[e - 1] = e - b;
                length[b] = e - b;
            }
            b = e;
        }
        b = e = 0;
        while (b != s)
        {
            int color = v[b];
            while (e != s && v[e] == color)
            {
                e++;
            }
            if (color == 0)
            {
                if (e - b == 1)
                {
                    if (e != 1)
                    {
                        if (length[e] != 1 && length[b - 1] != 1)
                        {
                            ans--;
                        }
                        if (length[b - 1] != 1)
                        {
                            length[e] = 2;
                        }
                    }
                }
            }
            b = e;
        }
        return ans;
    }
};

/*
39
54
6
5
9
1
2
3
*/

int main()
{
    Solution s;
    cout << s.minOperations(7862);
}