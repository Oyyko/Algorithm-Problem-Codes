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
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        if (head->next == nullptr)
            return head;
        if (head->next->next == nullptr)
            return head;
        vector<int> v;
        ListNode *p = head;
        while (p != nullptr)
        {
            v.push_back(p->val);
            p = p->next;
        }
        auto c = [&](int s, int e)
        {
            while (s < e)
            {
                swap(v[s], v[e]);
                s++;
                e--;
            }
        };
        int s{}, e{}, now_len{1}, max_len{1};
        while (e != v.size())
        {
            while (now_len < max_len)
            {
                e++;
                now_len++;
                cout << now_len << " " << max_len << "\n";
            }
            cout << "E:" << e << "S:" << s << endl;
            if (e - s % 2 == 1)
            {
                c(s, e);
            }
            s = e + 1;
            e = s;
            now_len = 1;
            max_len++;
        }

        //pr(v);
    }
};

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
    ss.reverseEvenLengthGroups(l[0]);
}