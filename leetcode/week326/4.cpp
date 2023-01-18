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
    bool is_prime(int number)
    {
        if (number < 2)
            return false;
        if (number == 2)
            return true;
        if (number % 2 == 0)
            return false;
        for (int i = 3; (i * i) <= number; i += 2)
        {
            if (number % i == 0)
                return false;
        }
        return true;
    }
    vector<int> p;
    vector<int> closestPrimes(int left, int right)
    {
        int last_p{};
        int ans1{-1}, ans2{-1};
        for (int i = right; i >= left; --i)
        {
            if (is_prime(i))
            {
                if (last_p == 0)
                {
                    last_p = i;
                }
                else
                {
                    if (ans1 == -1 && ans2 == -1)
                    {
                        ans1 = i;
                        ans2 = last_p;
                    }
                    else
                    {
                        if (last_p - i <= ans2 - ans1)
                        {
                            ans2 = last_p;
                            ans1 = i;
                        }
                    }
                }
                last_p = i;
            }
        }
        return vector<int>{ans1, ans2};
    }
};

int main()
{
}