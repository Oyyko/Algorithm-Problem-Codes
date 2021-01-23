// Using the sprase table
// Initial O(n log n) query O(1)
// It can be solved with RMQ~LCA transformation. And we build a Carsetian Tree so
// the problem can be solved with O(n) init and O(1) query.

// Using the sprase table
// Initial O(n log n) query O(1)
// It can be solved with RMQ~LCA transformation. And we build a Carsetian Tree so
// the problem can be solved with O(n) init and O(1) query.

#include <iostream>

using namespace std;

const int MAXM = 1000000;

int *costmax[21];

int main()
{
    int *Log2 = (int *)malloc(sizeof(int) * (MAXM + 10));
    for (int i = 0; i <= 20; ++i)
        costmax[i] = (int *)malloc(sizeof(int) * (MAXM + 10));
    costmax[0][1] = 1;
    Log2[1] = 0;
    for (long long i{2}, cnt{1}; i <= MAXM; ++i)
    {

        Log2[i] = 1 + Log2[i / 2];
        long long j{i};
        while (j != 1)
        {

            if (j <= MAXM && costmax[0][j])
            {
                cnt += costmax[0][j] - 1;
                break;
            }
            if (j % 2 == 1)
            {
                j = j * 3 + 1;
                cnt++;
            }
            else
            {
                j = j / 2;
                cnt++;
            }
        }
        costmax[0][i] = cnt;
        cnt = 1;
    }
    for (int j{1}; j <= 20; ++j)
    {
        int tmp = MAXM - (1 << j) + 1;
        for (int i{1}; i <= tmp; ++i)
        {
            costmax[j][i] = max(costmax[j - 1][i], costmax[j - 1][i + (1 << (j - 1))]);
        }
    }
    int l, r, k;
    while (~scanf("%d", &l) && ~scanf("%d", &r))
    {
        k = Log2[r - l + 1];
        printf("%d %d %lld\n", l, r, max(costmax[k][l], costmax[k][r + 1 - (1 << k)]));
    }
}