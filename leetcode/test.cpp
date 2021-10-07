#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

#include <map>
#include <unordered_map>

int main()
{
    unordered_map<int, int> hash;
    hash.insert(make_pair(1, 10));
    hash.insert(make_pair(2, 20));
    hash.insert(make_pair(3, 30));
    auto it = hash.find(10);
    cout << it->second;
}