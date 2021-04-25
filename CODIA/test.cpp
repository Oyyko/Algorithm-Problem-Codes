#include <iostream>
#include <set>

using namespace std;

int main()
{
    multiset<double> s;
    s.insert(23.9);
    s.insert(0.1 + 0.2);
    for (auto x : s)
    {
        cout << x << endl;
    }
    if (s.find(0.3) != s.end())
    {
        cout << "FIND";
    }
}