#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
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
    string complexNumberMultiply(string num1, string num2)
    {
        using pii = pair<int, int>;
        auto input = [&](string &num) -> pii
        {
            bool plus{false};
            int a{}, b{};
            bool an{}, bn{};
            for (auto &x : num)
            {
                if (x == '+')
                {
                    plus = 1;
                    continue;
                }
                if (x == 'i')
                {
                    break;
                }
                if (plus)
                {
                    if (x == '-')
                    {
                        bn = 1;
                        continue;
                    }
                    b *= 10;
                    b += x - '0';
                }
                else
                {
                    if (x == '-')
                    {
                        an = 1;
                        continue;
                    }
                    a *= 10;
                    a += x - '0';
                }
            }
            return {an ? -a : a, bn ? -b : b};
        };
        // (a+bi)(c+di)=(ac-bd)+(ad+bc)i
        auto mul = [](pii &&a, pii &&b) -> pii
        {
            return {a.first * b.first - a.second * b.second, a.first * b.second + a.second * b.first};
        };
        auto pr = [](pii &&x) -> string
        {
            return to_string(x.first) + "+" + to_string(x.second) + "i";
        };
        return pr(mul(input(num1), input(num2)));
    }
};

int main()
{
    string num1{"1+-1i"};
    string num2{"1+-1i"};
    Solution s;
    cout << s.complexNumberMultiply(num1, num2);
}