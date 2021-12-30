#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
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
    vector<string> findOcurrences(string text, string first, string second)
    {
        string now;
        int state{};
        vector<string> ans;
        for (auto &x : text)
        {
            if (x != ' ')
                now.push_back(x);
            else
            {
                switch (state)
                {
                case 0:
                    state += now == first;
                    break;
                case 1:
                    if (now == second)
                        state = 2;
                    else if (now == first)
                        state = 1;
                    else
                        state = 0;
                    break;
                case 2:
                    ans.push_back(now);
                    if (now == first)
                        if (first == second)
                            state = 2;
                        else
                            state = 1;
                    else
                        state = 0;
                    break;

                default:
                    break;
                }
                now.clear();
            }
        }

        switch (state)
                {
                case 0:
                    state += now == first;
                    break;
                case 1:
                    if (now == second)
                        state = 2;
                    else if (now == first)
                        state = 1;
                    else
                        state = 0;
                    break;
                case 2:
                    ans.push_back(now);
                    if (now == first)
                        if (first == second)
                            state = 2;
                        else
                            state = 1;
                    else
                        state = 0;
                    break;

                default:
                    break;
                }

        return ans;
    }
};

int main()
{
}