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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

#include <random>

class RandomizedSet
{
public:
    unordered_map<int, int> s;
    random_device gen;
    vector<int> all;
    RandomizedSet()
    {
        all.reserve(123456);
    }

    bool insert(int val)
    {
        auto itr = s.find(val);
        if (itr == s.end())
        {
            all.push_back(val);
            s[val] = all.size() - 1;
            return 1;
        }
        else
            return false;
    }

    bool remove(int val)
    {
        auto itr = s.find(val);
        if (itr == s.end())
            return false;
        int idx1 = itr->second;
        s[all.back()] = idx1;
        all[idx1] = all.back();
        all.pop_back();
        s.erase(val);
        return 1;
    }

    int getRandom()
    {
        int sz = s.size();
        return all[gen() % sz];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
}