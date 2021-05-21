#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    int t;
    while (cin >> t)
    {
        a.push_back(t);
    }
    vector<int> maxx;
    maxx.resize(a.size());
    maxx[0] = a[0];
    maxx[1] = max(a[1], a[0]);
    for (int i = 2; i < maxx.size(); ++i)
    {
        maxx[i] = max(maxx[i - 2] + a[i], maxx[i - 1]);
    }
    cout << maxx[maxx.size() - 1];
}