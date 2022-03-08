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
    string convertToBase7(int num)
    {
        string ans{};
        if (num == 0)
            return "0";
        else if (num < 0)
        {
            return "-" + convertToBase7(-num);
        }
        while (num)
        {
            ans.push_back('0' + num % 7);
            num /= 7;
        }
        for (int i{}, j = ans.size() - 1; i < j; i++, j--)
        {
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};

int main()
{
}