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
    int primePalindrome(int n)
    {
        switch (n)
        {
        case 1:
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
        case 5:
            return 5;
        case 6:
        case 7:
            return 7;

        default:
            break;
        }
        auto is_palind = [](int x) -> bool
        {
            int ans{};
            int xx{x};
            while (x > 0)
            {
                ans = 10 * ans + (x % 10);
                x /= 10;
            }
            return ans == xx;
        };
        auto is_prime = [](int x) -> bool
        {
            if (x < 2)
                return false;
            if (x < 25)
            {
                if (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19 || x == 23)
                    return true;
                return false;
            }
            for (int i = 5, _ = 0; i * i <= x; (_ == 0) ? (_ = 1, i += 2) : (_ = 0, i += 4))
                if (x % i == 0)
                    return false;
            return true;
        };
        int x = n % 6;
        switch (x)
        {
        case 0:
            n++;
            if (is_palind(n) && is_prime(n))
                return n;
            n += 4;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            n += 5 - x;
            break;

        default:
            break;
        }
        int _ = 0;
        while (true)
        {
            if (is_palind(n) && is_prime(n))
                return n;
            (_ == 0) ? (_ = 1, n += 2) : (_ = 0, n += 4);
            if (12 <= n && n <= 99)
            {
                n = 101;
                int x = n % 6;
                switch (x)
                {
                case 0:
                    n++;
                    if (is_palind(n) && is_prime(n))
                        return n;
                    n += 4;
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    n += 5 - x;
                    break;

                default:
                    break;
                }
                _ = 0;
            }
            if (1000 <= n && n <= 9999)
            {
                n = 10001;
                int x = n % 6;
                switch (x)
                {
                case 0:
                    n++;
                    if (is_palind(n) && is_prime(n))
                        return n;
                    n += 4;
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    n += 5 - x;
                    break;

                default:
                    break;
                }
                _ = 0;
            }
            if (100000 <= n && n <= 999999)
            {
                n = 1000001;
                int x = n % 6;
                switch (x)
                {
                case 0:
                    n++;
                    if (is_palind(n) && is_prime(n))
                        return n;
                    n += 4;
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    n += 5 - x;
                    break;

                default:
                    break;
                }
                _ = 0;
            }
            if (10000000 <= n && n <= 99999999)
            {
                n = 100000000;
                int x = n % 6;
                switch (x)
                {
                case 0:
                    n++;
                    if (is_palind(n) && is_prime(n))
                        return n;
                    n += 4;
                    break;
                case 1:
                case 2:
                case 3:
                case 4:
                    n += 5 - x;
                    break;

                default:
                    break;
                }
                _ = 0;
            }
        }
    }
};

int main()
{
    Solution s;
    int x;
    scanf("%d", &x);
    cout << s.primePalindrome(x);
}