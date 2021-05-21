#include <iostream>
#include <set>
#include <vector>
using namespace std;

int pp{};
int per[100];

void perm(vector<int> m)
{
    int ppp = pp;
    if (m.size() == 1)
    {
        per[pp] = m[0];
        for (int i = 0; i <= pp; ++i)
        {
            cout << per[i];
        }
        cout << endl;
        return;
    }
    vector<int> back;
    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        per[pp++] = *itr;
        back = m;
        m.erase(itr);
        perm(m);
        pp = ppp;
        m = back;
    }
}

int main()
{
    vector<int> x;
    int xx;
    while (cin >> xx)
    {
        x.push_back(xx);
    }
    perm(x);
}