#include <iostream>
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

struct Node
{
    char c;
    vector<Node *> child;
    int d = -1;
};

class Solution
{
public:
    int ans = -1;
    int dfs(Node *root)
    {
        int d1 = 0, d2 = 0;
        if (root->d != -1)
            return root->d;
        for (auto &x : root->child)
        {
            int d = dfs(x);
            root->d = max(root->d, d + 1);
            if (d > d1)
            {
                d2 = d1, d1 = d;
            }
            else if (d > d2)
            {
                d2 = d;
            }
        }
        if (root->d == -1)
            root->d = 1;
        // cout << root->c << " " << d1 + d2 + 1 << endl;
        ans = max(d1 + d2 + 1, ans);
        return root->d;
    }
    int longestPath(vector<int> &parent, string s)
    {
        Node *root = new Node;
        vector<Node *> nodes;
        int n = s.size();
        nodes.resize(n);
        for (auto &x : nodes)
            x = new Node;
        nodes[0] = (root);
        int i = 0;
        root->c = s[i];
        // cout << root->c << endl;
        for (int j = 0; j < n; ++j)
        {
            nodes[j]->c = s[j];
        }
        for (i = 1; i < n; ++i)
        {
            if (nodes[i]->c != nodes[parent[i]]->c)
                nodes[parent[i]]->child.push_back(nodes[i]);
        }
        // cout << "CNT" << nodes.size() << endl;
        for (auto &x : nodes)
        {
            dfs(x);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v{-1, 137, 65, 60, 73, 138, 81, 17, 45, 163, 145, 99, 29, 162, 19, 20, 132, 132, 13, 60, 21, 18, 155, 65, 13, 163, 125, 102, 96, 60, 50, 101, 100, 86, 162, 42, 162, 94, 21, 56, 45, 56, 13, 23, 101, 76, 57, 89, 4, 161, 16, 139, 29, 60, 44, 127, 19, 68, 71, 55, 13, 36, 148, 129, 75, 41, 107, 91, 52, 42, 93, 85, 125, 89, 132, 13, 141, 21, 152, 21, 79, 160, 130, 103, 46, 65, 71, 33, 129, 0, 19, 148, 65, 125, 41, 38, 104, 115, 130, 164, 138, 108, 65, 31, 13, 60, 29, 116, 26, 58, 118, 10, 138, 14, 28, 91, 60, 47, 2, 149, 99, 28, 154, 71, 96, 60, 106, 79, 129, 83, 42, 102, 34, 41, 55, 31, 154, 26, 34, 127, 42, 133, 113, 125, 113, 13, 54, 132, 13, 56, 13, 42, 102, 135, 130, 75, 25, 80, 159, 39, 29, 41, 89, 85, 19};
    cout << s.longestPath(v, "ajunvefrdrpgxltugqqrwisyfwwtldxjgaxsbbkhvuqeoigqssefoyngykgtthpzvsxgxrqedntvsjcpdnupvqtroxmbpsdwoswxfarnixkvcimzgvrevxnxtkkovwxcjmtgqrrsqyshxbfxptuvqrytctujnzzydhpal");
}