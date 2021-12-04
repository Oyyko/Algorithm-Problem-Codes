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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        stack<int> s;
        for (auto p = head; p != nullptr; p = p->next)
        {
            s.push(p->val);
        }
        ListNode *head1 = new ListNode(s.top());
        s.pop();
        ListNode *p = head1;
        while (!s.empty())
        {
            p->next = new ListNode(s.top());
            s.pop();
            p = p->next;
        }
        return head1;
    }
    void pr(ListNode *head)
    {
        for (auto p{head}; p != nullptr; p = p->next)
        {
            cout << p->val;
        }
    }
};

int main()
{
    Solution s;
    int i{1};
    0b10101010100000;//10912
    0b10011;//19
    ListNode *head = new ListNode(i++); // 1
    auto p = head;
    p->next = new ListNode(i++); // 2
    p = p->next;
    p->next = new ListNode(i++); // 3
    p = p->next;
    p->next = new ListNode(i++); // 4
    p = p->next;

    s.pr(s.reverseList(head));
}