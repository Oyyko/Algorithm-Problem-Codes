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

int main()
{
    const int M = 100000;
    vector<unordered_set<int>> fenjie(M + 5);
    for (int i{1}; i <= M; ++i)
    {
        for (int j{1}; i * j <= M; ++j)
        {
            fenjie[i * j].insert(i);
            fenjie[i * j].insert(j);
        }
    }
    cout << "{ ";
    for (int i = 1; i <= 100000; ++i)
    {

        cout << "{";

        cout << "}";
    }
    cout << " }";
}