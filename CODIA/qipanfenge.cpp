#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

int dp[15][9][9][9][9];
//dp[k,x1,y1,x2,y2] means if n=k and we cut the rectangle from (x1,y1) to (x2,y2), the min cost we need to pay

int prefix_sum[9][9]; // prefix sum. SUM FROM (1,1) to (x,y) is sum[x][y];

int sum_of_rectangle(int x1, int y1, int x2, int y2) // sum of rectangle whose left-above is (x1,y1) and right-down is (x2,y2)
{
    return prefix_sum[x2][y2] - prefix_sum[x2][y1 - 1] - prefix_sum[x1 - 1][y2] + prefix_sum[x1 - 1][y1 - 1];
}

int search(int k, int x1, int y1, int x2, int y2)
// cut k knives on rectangle(x1,y1,x2,y2), the min cost is search(k,x1,y1,x2,y2)
{
    int sum_of_rec;
    int square_of_sum_of_rec;
    if (dp[k][x1][y1][x2][y2] != -1)
    {
        return dp[k][x1][y1][x2][y2];
    }
    int minn = 0xffffff;
    if (k == 1) //cut no knife
    {
        sum_of_rec = sum_of_rectangle(x1, y1, x2, y2);
        square_of_sum_of_rec = sum_of_rec * sum_of_rec;
        dp[k][x1][y1][x2][y2] = square_of_sum_of_rec;
        return square_of_sum_of_rec;
    }

    // column_cut
    for (int breakpoint = x1; breakpoint < x2; ++breakpoint)
    {
        int right_part = sum_of_rectangle(breakpoint + 1, y1, x2, y2);
        int left_part = sum_of_rectangle(x1, y1, breakpoint, y2);
        square_of_sum_of_rec = min(search(k - 1, x1, y1, breakpoint, y2) + right_part * right_part, search(k - 1, breakpoint + 1, y1, x2, y2) + left_part * left_part);
        if (minn > square_of_sum_of_rec)
        {
            minn = square_of_sum_of_rec;
        }
    }

    // line_cut
    for (int breakpoint = y1; breakpoint < y2; ++breakpoint)
    {
        int above_part = sum_of_rectangle(x1, breakpoint + 1, x2, y2);
        int down_part = sum_of_rectangle(x1, y1, x2, breakpoint);
        square_of_sum_of_rec = min(search(k - 1, x1, y1, x2, breakpoint) + above_part * above_part, search(k - 1, x1, breakpoint + 1, x2, y2) + down_part * down_part);

        minn = min(minn, square_of_sum_of_rec);
    }

    dp[k][x1][y1][x2][y2] = minn;

    return minn;
}

void get_prefix_sum()
{
    int temp;
    for (int i = 0; i <= 8; ++i)
    {
        prefix_sum[0][i] = prefix_sum[i][0] = 0;
    }
    for (int i = 1; i <= 8; ++i)
    {
        for (int j = 1, s = 0; j <= 8; ++j)
        {
            cin >> temp;
            s += temp;
            prefix_sum[i][j] = prefix_sum[i - 1][j] + s;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    get_prefix_sum();
    memset(dp, -1, sizeof(dp));
    double res = n * search(n, 1, 1, 8, 8) - prefix_sum[8][8] * prefix_sum[8][8];
    //cout << "res: " << res << " n:" << n << endl;
    printf("%.3lf\n", sqrt(res / ((n + 0.0) * (n + 0.0))));

    return 0;
}