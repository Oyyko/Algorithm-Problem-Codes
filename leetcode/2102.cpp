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

class SORTracker
{
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator cur;

public:
    SORTracker()
    {
        s.emplace(0, ""); 
        cur = s.begin();
    }

    void add(string name, int score)
    {
        pair<int, string> p = {-score, name};
        s.insert(p);
        if (p < *cur)
            --cur;
    }

    string get()
    {
        return cur++->second;
    }
};

int main()
{
}