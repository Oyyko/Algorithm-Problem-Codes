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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void p(ListNode *&x)
    {
        if (x == nullptr)
            return;
        x = x->next;
    }
    int v(ListNode *x)
    {
        if (x == nullptr)
            return 0;
        return x->val;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode((l1->val + l2->val) % 10);
        int cin = (l1->val + l2->val) / 10;
        l1 = l1->next, l2 = l2->next;
        ListNode *tmp = ans;
        while (l1 != nullptr || l2 != nullptr)
        {
            tmp->next = new ListNode;
            tmp = tmp->next;
            tmp->val = (v(l1) + v(l2) + cin);
            cin = tmp->val / 10;
            tmp->val %= 10;
            p(l1), p(l2);
        }
        if (cin)
        {
            tmp->next = new ListNode(cin);
        }
        return ans;
    }
};

int main()
{
}