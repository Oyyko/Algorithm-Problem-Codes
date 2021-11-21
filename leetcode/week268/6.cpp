#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int dp[110][2][110][110]; //dp数组
int x[110], temp[110];
int dfs(int pos, int sta, bool limit, int k, int len)
{
    if (pos < 0)
    {
        if (sta)
            return k;
        else
            return 1;
    }
    if (!limit && dp[pos][sta][len][k] != -1)
        return dp[pos][sta][len][k];
    long long sum = 0, up;
    up = limit ? x[pos] : k - 1;
    for (int i = 0; i <= up; i++)
    {
        temp[pos] = i;
        if (i == 0 && len == pos) //递归遍历，从最小的开始
            sum += dfs(pos - 1, sta, limit && (i == up), k, len - 1);
        else if (sta && pos < (len + 1) / 2) //判断是否回文
            sum += dfs(pos - 1, sta && i == temp[len - pos], limit && (i == up), k, len);
        else
            sum += dfs(pos - 1, sta, limit && (i == up), k, len);
    }
    if (!limit)
        dp[pos][sta][len][k] = sum; //记忆化
    return sum;
}

int f(int a, int k)
{
    int pos = 0;
    while (a) //k进制下提取每一位
    {
        x[pos++] = a % k;
        a /= k;
    }
    return dfs(pos - 1, 1, true, k, pos - 1);
}
int main()
{
    memset(dp, -1, sizeof(dp));
    cout << f(1, 7);
    return 0;
}