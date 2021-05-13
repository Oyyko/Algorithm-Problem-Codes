#include <iostream>
#include <cstring> // memset

using namespace std;

int matrix[105][105]; // at first storage data, then matrix[a][b] storage sum of original matrix[1..a][b]
int column_sum[105];  //column[k] storage sum of original matrix[i..j][k]
int n;                // size

int max_array_sum() // compute the max matrix sum of matrix[i..j][x..y] where i and j are fixed
{
    int max_sum{};
    int max_when_right_is_now_i{};
    for (int i = 1; i <= n; ++i)
    {
        if (max_when_right_is_now_i > 0)
        {
            max_when_right_is_now_i += column_sum[i];
        }
        else
        {
            max_when_right_is_now_i = column_sum[i];
        }
        max_sum = max(max_sum, max_when_right_is_now_i);
    }
    return max_sum;
}

int main()
{
    int answer{-1};
    int now_answer{};
    cin >> n;

    memset(matrix, 0, sizeof(matrix));
    for (int k1 = 1; k1 <= n; ++k1)
    {
        for (int k2 = 1; k2 <= n; ++k2)
        {
            cin >> matrix[k1][k2];
        }
    } //O(n^2), read in

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            matrix[i][j] += matrix[i - 1][j];
        }
    } //O(n^2), prefix sum

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                column_sum[k] = matrix[j][k] - matrix[i - 1][k]; // sum of matrix[i..j][k]
            }
            now_answer = max_array_sum();
            answer = max(now_answer, answer);
        }
    } //O(n^3)

    cout << answer;
}