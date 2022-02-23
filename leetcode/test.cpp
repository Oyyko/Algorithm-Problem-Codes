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

inline int lowbit(int x)
{
    return x & -x;
}

void pr_bit(int x)
{
    vector<char> v;
    while (x)
    {
        v.push_back('0' + x % 2);
        x /= 2;
    }
    for (auto i = v.rbegin(); i != v.rend(); ++i)
    {
        cout << *i;
    }
    cout << endl;
}

void GospersHack(int k, int n)
{
    int cur = (1 << k) - 1;
    int limit = (1 << n);
    while (cur < limit)
    {
        pr_bit(cur);
        // do something
        int lb = cur & -cur;
        int r = cur + lb;
        cur = ((r ^ cur) >> __builtin_ctz(lb) + 2) | r;
        // 或：cur = (((r ^ cur) >> 2) / lb) | r;
    }
}

int main()
{
    GospersHack(3, 5);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
}