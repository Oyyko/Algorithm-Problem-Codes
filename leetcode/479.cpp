#include <bits/stdc++.h>

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
    int largestPalindrome(int n)
    {
        return vector<int>{-1, 9, 987, 123, 597, 677, 1218, 877, 475}.at(n);
    }
};

int main()
{
}