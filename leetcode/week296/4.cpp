#include <iostream>
#include <random>
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

#include <list>

void rev(string &x)
{
    int n = x.size();
    int l = 0, r = n - 1;
    while (l < r)
    {
        swap(x[l], x[r]);
        l++, r--;
    }
}

class TextEditor
{
public:
    list<char> s;
    decltype(s.begin()) cur;
    TextEditor()
    {
        cur = s.begin();
    }
    void show()
    {
        for (auto &x : s)
        {
            cout << x;
        }
        cout << endl;
    }

    void addText(string text)
    {
        for (auto &x : text)
            s.insert(cur, x);
    }

    int deleteText(int k)
    {
        int ans{};
        if (cur != s.begin())
            cur--;
        else
            return 0;
        while (cur != s.begin() && k)
        {
            s.erase(cur--);
            k--;
            ans++;
        }
        if (k && cur == s.begin())
        {
            s.erase(cur);
            ans++;
            cur = s.begin();
        }
        else
        {
            cur++;
        }
        return ans;
    }

    string cursorLeft(int k)
    {
        while (cur != s.begin() && k)
        {
            cur--;
            k--;
        }
        int ll = 10;
        string res;
        auto cur2 = cur;
        while (ll && cur != s.begin())
        {
            ll--;
            cur--;
            res.push_back(*cur);
        }
        rev(res);
        cur = cur2;
        return res;
    }

    string cursorRight(int k)
    {
        while (k && cur != s.end())
        {
            k--;
            cur++;
        }
        int ll = 10;
        string res;
        auto cur2 = cur;
        while (ll && cur != s.begin())
        {
            ll--;
            cur--;
            res.push_back(*cur);
        }
        cur = cur2;
        rev(res);
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main()
{
    TextEditor t;
    t.addText("leetcode");
    cout << t.deleteText(4) << endl;
    t.addText("practice");
    cout << t.cursorRight(3) << endl;
    cout << t.cursorLeft(8) << endl;
    cout << t.deleteText(10) << endl;
    cout << t.cursorLeft(2) << endl;
    cout << t.cursorRight(6) << endl;
}