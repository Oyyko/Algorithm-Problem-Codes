#include <iostream>
#include <vector>

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

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int ans{};
        int first_pos[32];
        for (int i = 0; i < 32; ++i)
        {
            first_pos[i] = -2;
        }
        first_pos[0] = -1;
        int now{};
        for (int i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case 'a':
                now ^= 0b00001;
                break;
            case 'e':
                now ^= 0b00010;
                break;
            case 'i':
                now ^= 0b00100;
                break;
            case 'o':
                now ^= 0b01000;
                break;
            case 'u':
                now ^= 0b10000;
                break;

            default:
                break;
            }
            if (first_pos[now] != -2)
            {
                ans = max(ans, i - first_pos[now]);
            }
            else
            {
                first_pos[now] = i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << "leetcodeisgreat"s.size() << endl;
    cout << s.findTheLongestSubstring("leetcodeisgreat"s);
}