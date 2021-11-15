#include <bits/stdc++.h>

using namespace std;

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
    void change(ListNode *s, ListNode *e)
    {
        ListNode *res = e->next;
        ListNode *nnn;
        ListNode *n = s->next;
        ListNode *ss = s;
        while (n != e)
        {
            nnn = n->next;
            n->next = s;
            s = n;
            n = nnn;
        }
        n->next = s;
        ss->next = res;
    }
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        if (head->next == nullptr || head->next->next == nullptr)
            return head;
        ListNode *now_start, *now_end, *last_end;
        now_start = head->next;
        last_end = head;
        now_end = head->next;
        int now_len{1}, max_len{2};
        while (1)
        {
            while (now_len < max_len)
            {
                now_end = now_end->next;
                now_len++;
                if (now_end == nullptr)
                    break;
                if (now_end->next == nullptr)
                    break;
            }
            if (now_end == nullptr)
                break;
            if (now_end->next == nullptr)
                break;
            if (now_len % 2 == 0)
            {
                change(now_start, now_end);
                last_end->next = now_end;
                now_len = 1;
                max_len++;
                last_end = now_start;
                now_end = now_start->next;
                now_start = now_start->next;
            }
            else
            {
                last_end = now_end;
                now_len = 1;
                max_len++;
                now_start = now_end->next;
                now_end = now_end->next;
            }
        }
        if (now_end == nullptr)
        {
            return head;
        }
        if (now_len % 2 == 0)
        {
            change(now_start, now_end);
            last_end->next = now_end;
        }
        return head;
    }
};

void pp(ListNode *h)
{
    while (h != nullptr)
    {
        cout << h->val;
        h = h->next;
    }
}

int main()
{
    Solution s;
    ListNode *l[10];
    for (auto &x : l)
    {
        x = new ListNode;
    }
    for (int i = 0; i < 10; ++i)
    {
        l[i]->val = i;
        l[i]->next = i != 9 ? l[i + 1] : nullptr;
    }
    s.reverseEvenLengthGroups(l[0]);
    pp(l[0]);
}
