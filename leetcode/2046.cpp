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
    ListNode *sortLinkedList(ListNode *head)
    {
        auto res = head;
        ListNode *temp;
        while (head->next)
        {
            if (head->next->val >= 0)
                head = head->next;
            else
            {
                temp = head->next;
                head->next = temp->next;
                temp->next = res;
                res = temp;
            }
        }
        return res;
    }
};

int main()
{
}