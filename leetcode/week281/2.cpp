#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
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
    ListNode *mergeNodes(ListNode *head)
    {
        vector<int> num;
        num.reserve(200005);
        ListNode *p = head;
        while (p != nullptr)
        {
            num.push_back(p->val);
            p = p->next;
        }
        ListNode *ans = new ListNode;
        ListNode *pp = ans;
        bool flag = 0;
        int temp{};
        for (auto &x : num)
        {
            if (flag)
            {
                if (x == 0)
                {
                    pp->val = temp;
                    pp->next = nullptr;
                    temp = 0;
                    flag = 0;
                }
                else
                {
                    temp += x;
                }
            }
            else
            {
                if (x != 0)
                {
                    flag = 1;
                    temp += x;
                    pp->next = new ListNode;
                    pp = pp->next;
                }
            }
        }
        return ans->next;
    }
};

int main()
{
    Solution s;
    vector<int> v{};
}