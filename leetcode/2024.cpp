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
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int ans = -1;
        int n = answerKey.size();
        int l = 0, r = 0;
        char c = 'T';
        int sum{};
        for (; r < n; ++r)
        {
            sum += c != answerKey[r];
            while (sum > k)
            {
                sum -= answerKey[l] != c;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        l = r = 0;
        c = 'F';
        sum = 0;
        for (; r < n; ++r)
        {
            sum += c != answerKey[r];
            while (sum > k)
            {
                sum -= answerKey[l] != c;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main()
{
}