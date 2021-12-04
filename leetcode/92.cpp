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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        int cnt = 1;
        auto p = head;
        ListNode *pp = nullptr;
        for (; cnt != left; pp = p, p = p->next, cnt++)
            ;
        auto a = p;
        auto b = p->next;
        auto c = p->next->next;
        cnt++;
        while (c != nullptr && cnt != right)
        {
            b->next = a;
            a = b;
            b = c;
            c = c->next;
            cnt++;
        }
        b->next = a;
        // cout << b->val;
        // cout << a->val;
        // cout << c->val;
        p->next = c;
        if (pp == nullptr)
        {
            return b;
        }
        pp->next = b;
        return head;
    }
};

int main()
{
}