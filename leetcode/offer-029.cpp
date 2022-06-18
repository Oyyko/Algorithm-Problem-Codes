#include <iostream>
#include <random>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <numeric>
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

template <class T>
void pr(vector<vector<T>> x)
{
    for (auto &a : x)
    {
        for (auto &b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T upper_divide(T a, T b)
{
    return (a - 1) / b + 1;
}

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next)
    {
        val = _val;
        next = _next;
    }
};

class Solution
{
public:
    Node *insert(Node *head, int insertVal)
    {
        Node *node = new Node(insertVal);
        if (head == nullptr)
        {
            node->next = node;
            return node;
        }
        if (head->next == head)
        {
            head->next = node;
            node->next = head;
            return head;
        }
        Node *curr = head, *next = head->next;
        while (next != head)
        {
            if (insertVal >= curr->val && insertVal <= next->val)
            {
                break;
            }
            if (curr->val > next->val)
            {
                if (insertVal > curr->val || insertVal < next->val)
                {
                    break;
                }
            }
            curr = curr->next;
            next = next->next;
        }
        curr->next = node;
        node->next = next;
        return head;
    }
};

int main()
{
}