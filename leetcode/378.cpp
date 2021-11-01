#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void pr(vector<T> x)
{
    for (auto a : x)
    {
        cout << a;
    }
    cout << endl;
}

class Solution
{
private:
    int count(vector<vector<int>> &mat, int mid)
    {
        const int n = mat.size();
        int cnt{}, row{}, col{n - 1};
        while (row < n && col >= 0)
        {
            if (mid >= mat[row][col])
            {
                cnt += col + 1;
                row++;
            }
            else
            {
                col--;
            }
        }
        return cnt;
    }

public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        const int n = matrix.size();
        int l = matrix[0][0];
        int h = matrix[n - 1][n - 1];
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            int cnt = count(matrix, mid);
            if (cnt < k)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return l;
    }
};

int main()
{
}