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

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        if (prerequisites.empty())
            return vector<bool>(queries.size(), false);
        vector<vector<bool>> floyd(numCourses, vector<bool>(numCourses, false));
        for (auto x : prerequisites)
            floyd[x[0]][x[1]] = true;
        for (int mid{}; mid < numCourses; ++mid)
            for (int i{}; i < numCourses; ++i)
                for (int j{}; j < numCourses; ++j)
                    floyd[i][j] = floyd[i][j] || (floyd[i][mid] && floyd[mid][j]);
        vector<bool> ans;
        for (auto x : queries)
            ans.push_back(floyd[x[0]][x[1]]);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> aa{{1, 2}, {1, 0}, {2, 0}};
    vector<vector<int>> q{{1, 0}, {1, 2}};
    pr(s.checkIfPrerequisite(3, aa, q));
}