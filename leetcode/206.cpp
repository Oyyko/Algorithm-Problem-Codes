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
        if (head->next == nullptr)
            return head;
        auto a = head;
        auto b = head->next;
        auto c = head->next->next;
        head->next = nullptr;
        while (c != nullptr)
        {
            b->next = a;
            a = b;
            b = c;
            c = c->next;
        }
        b->next = a;
        return b;
    }
};

int main()
{
}