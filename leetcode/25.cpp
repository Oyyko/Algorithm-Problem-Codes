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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        auto rev = [&](ListNode *prev, ListNode *l, ListNode *r, ListNode *succ) -> void
        {
            auto a = l;
            auto b = a->next;
            auto c = b->next;
            while (b != r)
                b->next = a, a = b, b = c, c = c->next;
            b->next = a;
            l->next = succ;
            if (prev != nullptr)
                prev->next = r;
            else
                head = r;
        };
        auto p = head;
        int cnt{};
        ListNode *pp = nullptr;
        ListNode *nextp;
        decltype(pp) nextpp;
        while (p != nullptr)
        {
            cnt++;
            nextp = p->next;
            if (cnt == k)
            {
                nextpp = pp == nullptr ? head : pp->next;
                cnt = 0;
                rev(pp, pp == nullptr ? head : pp->next, p, p->next);
                pp = nextpp;
            }
            p = nextp;
        }
        return head;
    }
};

void P(ListNode *h)
{
    for (; h != nullptr; h = h->next)
        cout << h->val;
    cout << endl;
}

int main()
{
    ListNode *p[10];
    for (int i = 1; i <= 5; ++i)
        p[i] = new ListNode;
    for (int i = 1; i <= 5; ++i)
        p[i]->next = i <= 4 ? p[i + 1] : nullptr;
    for (int i = 1; i <= 5; ++i)
        p[i]->val = i;
    Solution s;
    auto ggg = s.reverseKGroup(p[1], 2);
    P(ggg);
}