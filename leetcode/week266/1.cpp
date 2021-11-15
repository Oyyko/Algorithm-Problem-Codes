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
    int countVowelSubstrings(string word)
    {
        int ans{};
        if (word.length() < 5)
            return 0;
        int l = word.length();
        for (int i = 0; i < l; ++i)
        {
            int num{};
            for (int j = i; j < l; ++j)
            {
                char c = word[j];
                switch (c)
                {
                case 'a':
                    num = num | 1;
                    break;
                case 'e':
                    num = num | 2;
                    break;
                case 'i':
                    num = num | 4;
                    break;
                case 'o':
                    num = num | 8;
                    break;
                case 'u':
                    num = num | 16;
                    break;

                default:
                    goto A;
                    break;
                }
                if (num == 31)
                    ans++;
            }
        A:
            continue;
        }
        return ans;
    }
};

int main()
{
}