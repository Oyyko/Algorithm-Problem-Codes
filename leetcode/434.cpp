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
    int countSegments(string s)
    {
        int state = 0;
        int cnt{};
        for (auto c : s)
        {
            if (state == 0)
            {
                if (c != ' ')
                {
                    cnt++;
                    state = 1;
                }
            }
            else
            {
                if (c == ' ')
                {
                    cnt++;
                    state = 0;
                }
            }
        }
        return (cnt + 1) / 2;
    }
};

int main()
{
}