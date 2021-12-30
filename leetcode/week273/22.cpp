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
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        int l = s.size();
        if (n == 1)
            return vector<int>(l, 0);
        vector<int> ans(l, 0);
        int x = startPos[0];
        int y = startPos[1];
        for (int i = 0; i < l; ++i)
        {
            x = startPos[0];
            y = startPos[1];
            for (int k = i; k < l; ++k)
            {
                char c = s[k];
                
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> ss{0, 1};
    string in{"RRDDLU"};
    pr(s.executeInstructions(3, ss, in));
}