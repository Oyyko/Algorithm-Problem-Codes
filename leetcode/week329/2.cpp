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
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        sort(score.begin(), score.end(), [&k](const vector<int> &a, const vector<int> &b)
             { return a[k] > b[k]; });
        return score;
    }
};

int main()
{
}