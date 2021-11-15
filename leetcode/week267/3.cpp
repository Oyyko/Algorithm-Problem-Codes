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
    ListNode *c(ListNode *s, ListNode *e)
    {
        ListNode *ans = e->next;
        ListNode *n = s->next;
        ListNode *nn;
        while (n != e)
        {
            nn = n->next;
            n->next = s;
            s = n;
            n = nn;
        }
        n->next = s;
        return ans;
    }
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        if (head->next == nullptr)
            return head;
        if (head->next->next == nullptr)
            return head;
        int now_len = 1;
        int max_len = 2;
        ListNode *last_end = head;
        ListNode *now_start = last_end->next;
        ListNode *now_end = now_start;
        while (now_end != nullptr)
        {
            ListNode *nnn;
            while (now_end != nullptr && now_len < max_len)
            {
                now_end = now_end->next;
                now_len++;
            }
            printf("%d\n", 777);
            cout << now_start->val << now_end->val << endl;
            if (now_end != nullptr && now_len % 2 == 0)
            {
                nnn = c(now_start, now_end);
                last_end->next = now_end;
                last_end = now_start;
                now_start->next = nnn;
                now_start = nnn;
                now_end = nnn;
                now_len = 1;
                max_len++;
            }
            if (now_end != nullptr && now_len % 2 == 1)
            {
                last_end = now_end;
                now_start = now_end->next;
                now_end = now_end->next;
                now_len = 1;
                max_len++;
            }
        }
        ListNode *p = now_start;
        now_len = 0;
        while (p->next != nullptr)
        {
            p = p->next;
            now_len++;
        }
        if (now_len % 2 == 0)
        {
            c(now_start, p);
            last_end->next = p;
            now_start->next = nullptr;
        }
        return head;
    }
};

void pp(ListNode *h)
{
    while (h != nullptr)
    {
        cout << h->val << " ";
        h = h->next;
    }
    cout << "\n";
}
int main()
{
    Solution ss;
    ListNode *l[10];
    for (int i = 0; i <= 9; ++i)
    {
        l[i] = new ListNode;
    }
    for (int i = 0; i <= 8; ++i)
    {
        l[i]->next = l[i + 1];
        l[i]->val = i;
    }
    l[9]->val = 9;
    l[9]->next = nullptr;
    pp(l[0]);
    ss.reverseEvenLengthGroups(l[0]);
    pp(l[0]);
}