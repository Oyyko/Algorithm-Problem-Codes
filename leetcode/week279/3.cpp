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

class Bitset
{

private:
    vector<bool> v;
    int ones;
    bool fanzhuan{false};

public:
    Bitset(int size)
    {
        v = vector<bool>(size, 0);
        ones = 0;
    }

    void fix(int idx)
    {
        if (!fanzhuan)
        {
            if (v[idx] == 0)
                ones++;
            v[idx] = 1;
        }
        else
        {
            if (v[idx] == 1)
                ones++;
            v[idx] = 0;
        }
    }

    void unfix(int idx)
    {
        if (!fanzhuan)
        {
            if (v[idx] == 1)
                ones--;
            v[idx] = 0;
        }
        else
        {
            if (v[idx] == 0)
                ones--;
            v[idx] = 1;
        }
    }

    void flip()
    {
        fanzhuan = !fanzhuan;
        ones = v.size() - ones;
    }

    bool all()
    {
        return ones == v.size();
    }

    bool one()
    {
        return ones >= 1;
    }

    int count()
    {
        return ones;
    }

    string toString()
    {
        string x{};
        if (!fanzhuan)
            for (const auto &xx : v)
            {

                if (xx == 1)
                    x.push_back('1');
                else
                    x.push_back('0');
            }
        else
        {
            for (const auto &xx : v)
            {
                if (xx == 0)
                    x.push_back('1');
                else
                    x.push_back('0');
            }
        }
        return x;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

int main()
{
}