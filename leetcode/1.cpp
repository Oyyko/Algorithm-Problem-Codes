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

int main()
{
    vector<int> v{1, 7, 7, 7, 8};
    auto itr = lower_bound(v.begin(), v.end(), 7);
    cout << itr - v.begin();
    auto itr2 = upper_bound(v.begin(), v.end(), 7);
    cout << itr2 - v.begin();
    [1,2)
}