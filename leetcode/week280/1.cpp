#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
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
    int countOperations(int num1, int num2)
    {
        int cnt{};
        while (num1 != 0 && num2 != 0)
        {
            if (num1 >= num2)
            {
                num1 -= num2;
            }
            else
            {
                num2 -= num1;
            }
            cnt++;
        }
        return cnt;
    }
};

int main()
{
}