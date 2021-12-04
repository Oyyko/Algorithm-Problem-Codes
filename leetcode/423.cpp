#include <bits/stdc++.h>

using namespace std;
//2021 11 24 一个美好的一天 写了四道图论题
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

/*
zero
one
two
three
four
five
six
seven
eight
nine
*/

/*
x->6
g->8
o->1,2,4
n->1,7,9(2n)
e->1,3(2e),5,7(2e),8,9
r->0,3,4
f->4,5
v->5,7
h->3,8
i->5,6,8,9
t->2,3,8
/*

/*
x->6
g->8
h->3
r->4
f->5
v->7
i->9
t->2
o->1
z->0

*/

class Solution
{
public:
    inline int c(int x)
    {
        return x >= 0 ? x : 0;
    }
    string originalDigits(string s)
    {
        vector<int> cnt(256, 0);
        for (const auto &x : s)
            cnt[x]++;
        vector<int> cnt2(10, 0);
        cnt2[0] = cnt['z'];
        cnt['e'] -= cnt['z'];
        cnt['r'] -= cnt['z'];
        cnt['o'] -= cnt['z'];
        // six
        cnt2[6] = cnt['x'];
        cnt['s'] -= cnt['x'];
        cnt['i'] -= cnt['x'];

        // eight
        cnt2[8] = cnt['g'];
        cnt['e'] -= cnt['g'];
        cnt['i'] -= cnt['g'];
        cnt['h'] -= cnt['g'];
        cnt['t'] -= cnt['g'];
        //three
        cnt2[3] = cnt['h'];
        cnt['t'] -= cnt['h'];
        cnt['r'] -= cnt['h'];
        cnt['e'] -= cnt['h'];
        cnt['e'] -= cnt['h'];
        //four
        cnt2[4] = cnt['r'];
        cnt['f'] -= cnt['r'];
        cnt['o'] -= cnt['r'];
        cnt['u'] -= cnt['r'];

        //five
        cnt2[5] = cnt['f'];
        cnt['i'] -= cnt['f'];
        cnt['v'] -= cnt['f'];
        cnt['e'] -= cnt['f'];
        //nine
        cnt2[9] = cnt['i'];
        cnt['n'] -= cnt['i'];
        cnt['n'] -= cnt['i'];
        cnt['e'] -= cnt['i'];
        //two -t
        cnt2[2] = cnt['t'];
        cnt['w'] -= cnt['t'];
        cnt['o'] -= cnt['t'];
        //one -o
        cnt2[1] = cnt['o'];
        cnt['n'] -= cnt['o'];
        cnt['e'] -= cnt['o'];
        // seven
        cnt2[7] = cnt['v'];
        string ans{};
        for (int i{}; i < 10; ++i)
        {
            for (int j{}; j < cnt2[i]; ++j)
            {
                ans.append(to_string(i));
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.originalDigits("owoztneoer"s);
}