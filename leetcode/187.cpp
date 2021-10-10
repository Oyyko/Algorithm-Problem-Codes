#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a << endl;
    }
    cout << endl;
}

class Solution
{
private:
    char cnt[1048577] = {0};
    char encode[120];
    int poww(int a, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return a;
        }
        int half = poww(a, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * a;
        }
    }

public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        encode['A'] = 0;
        encode['T'] = 1;
        encode['C'] = 2;
        encode['G'] = 3;
        if (s.length() <= 10)
        {
            return {};
        }
        int code{};
        auto p = s.begin();
        for (int i = 0; i <= 9; ++i)
        {
            code += encode[*p] * poww(4, i);
            p++;
        }
        cnt[code]++;
        for (; p != s.end(); p++)
        {
            code /= 4;
            code += encode[*p] * poww(4, 9);
            if (cnt[code] == 0)
            {
                cnt[code]++;
            }
            else if (cnt[code] == 1)
            {
                cnt[code]++;
                ans.push_back(s.substr(p - s.begin() - 9, 10));
            }
            else
            {
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    pr(s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"s));
}