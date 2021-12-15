#include <bits/stdc++.h>

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
    ListNode *deleteMiddle(ListNode *head)
    {
        int l{};
        for (auto p = head; p != nullptr; p = p->next)
        {
            l++;
        }
        if (l == 1)
            return nullptr;
        int mid = l / 2;
        ListNode *pp = nullptr;
        auto p = head;
        int cnt{};
        for (; cnt != mid; p = p->next, cnt++)
        {
            pp = p;
        }
        pp->next = p->next;

        return head;
    }
};

int main()
{
    ListNode *p[10];
    p[2] = new ListNode(2);
    p[1] = new ListNode(1, p[2]);
    Solution s;
    s.deleteMiddle(p[1]);
    cout << (p[1]->next == nullptr);
}