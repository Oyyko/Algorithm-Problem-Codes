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
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;
        auto mid_node = [](ListNode *head) -> ListNode *
        {
            auto slow = head;
            auto fast = head;
            while (fast->next != nullptr && fast->next->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        };
        auto reverse_list = [](ListNode *head)
        {
            ListNode *prev = nullptr;
            ListNode *now = head;
            ListNode *nextt;
            while (now != nullptr)
            {
                nextt = now->next;
                now->next = prev;
                prev = now;
                now = nextt;
            }
            return prev;
        };
        auto merge_list = [](ListNode *l1, ListNode *l2) -> void
        {
            ListNode *l1t, *l2t;
            while (l1 != nullptr && l2 != nullptr)
            {
                l1t = l1->next;
                l2t = l2->next;
                l1->next = l2;
                l1 = l1t;
                l2->next = l1;
                l2 = l2t;
            }
        };
        auto mid = mid_node(head);
        auto l1 = head;
        auto l2 = mid->next;
        mid->next = nullptr;
        l2 = reverse_list(l2);
        merge_list(l1, l2);
    }
};

int main()
{
}