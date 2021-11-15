#include <bits/stdc++.h>

using namespace std;

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
    string decodeCiphertext(string encodedText, int rows)
    {
        if (encodedText == ""s)
        {
            return ""s;
        }
        if (rows == 1)
            return encodedText;
        int l = encodedText.length() / rows;
        vector<vector<char>> v(l, vector<char>(rows, ' '));
        int ll{}, rr{};
        for (auto x : encodedText)
        {
            v[ll][rr] = x;
            ll++;
            if (ll == l)
            {
                ll = 0;
                rr++;
            }
        }
        int x{};
        int y{};
        int last_x{};
        string ans{};
        int xxxx{1};
        while (!(x == l - 1 && y == 0))
        {
            ans.push_back(v[x][y]);
            x++, y++;
            if (y == rows)
            {
                y = 0;
                x = last_x + 1;
                last_x = x;
            }
            if (x == l)
            {
                x = last_x + 1;
                y = 0;
                last_x = x;
            }
        }
        ans.push_back(v[l - 1][0]);
        auto m = ans.end() - 1;
        for (;; m--)
        {
            if (*m != ' ')
                break;
        }
        ans.resize(m - ans.begin() + 1);
        return ans;
    }
};

int main()
{
    string s{"iveo    eed   l te   olc"};
    Solution ss;
    cout << ss.decodeCiphertext(s, 4);
}