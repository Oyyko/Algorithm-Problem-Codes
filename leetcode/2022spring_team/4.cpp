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

struct mian
{
    int leng_up;
    int leng_down;
    int leng_left;
    int leng_right;
    int jiao1, jiao2, jiao3, jiao4;
    mian() { leng_down = leng_left = leng_up = leng_right = jiao1 = jiao2 = jiao3 = jiao4 = 0; }
    void xuan_zhuan()
    {
        tie(leng_up, leng_left, leng_down, leng_right) = make_tuple(leng_left, leng_down, leng_right, leng_up);
        tie(jiao1, jiao2, jiao3, jiao4) = make_tuple(jiao3, jiao1, jiao4, jiao2);
    }
    void fan_zhuan_zuo_you()
    {
        swap(leng_up, leng_down);
        swap(leng_left, leng_right);
        swap(jiao1, jiao3);
        swap(jiao2, jiao4);
    }
    void fan_zhuan_shangxia()
    {
        
    }
};

class Solution
{
public:
    int man_leng;
    vector<vector<int>> mian2vtx{{2, 3, 4, 5}, {0, 1, 6, 7}, {0, 2, 6, 4}, {3, 1, 5, 7}, {6, 7, 4, 5}};
    vector<vector<int>> mian2edge{{0, 3, 1, 2}, {8, 10, 9, 11}, {1, 9, 4, 6}, {2, 11, 7, 5}, {8, 10, 9, 11}};
    bool charu_mian(int loc, vector<int> &vtx, vector<int> &edges, mian m)
    {
        if (m.jiao1)
        {
            if (vtx[mian2vtx[loc][0]] == 1)
                return false;
            vtx[mian2vtx[loc][0]] = 1;
        }
        if (m.jiao2)
        {
            if (vtx[mian2vtx[loc][1]] == 1)
                return false;
            vtx[mian2vtx[loc][1]] = 1;
        }
        if (m.jiao3)
        {
            if (vtx[mian2vtx[loc][2]] == 1)
                return false;
            vtx[mian2vtx[loc][2]] = 1;
        }
        if (m.jiao4)
        {
            if (vtx[mian2vtx[loc][3]] == 1)
                return false;
            vtx[mian2vtx[loc][3]] = 1;
        }
        if (m.leng_up & edges[mian2edge[loc][0]])
            return 0;
        if (m.leng_down & edges[mian2edge[loc][1]])
            return 0;
        if (m.leng_left & edges[mian2edge[loc][2]])
            return 0;
        if (m.leng_right & edges[mian2edge[loc][3]])
            return 0;
        edges[mian2edge[loc][0]] |= m.leng_up;
        edges[mian2edge[loc][1]] |= m.leng_down;
        edges[mian2edge[loc][2]] |= m.leng_left;
        edges[mian2edge[loc][3]] |= m.leng_right;
        return 1;
    }
    bool check(const vector<int> &per, vector<mian> m, vector<int> vtx, vector<int> edges)
    {
        for (int i1 = 1; i1 <= 4; ++i1)
        {
            m[per[0]].xuan_zhuan();
            for (int i2 = 1; i2 <= 4; ++i2)
            {
                m[per[1]].xuan_zhuan();
                for (int i3 = 1; i3 <= 4; ++i3)
                {
                    m[per[2]].xuan_zhuan();

                    for (int i4 = 1; i4 <= 4; ++i4)
                    {
                        m[per[3]].xuan_zhuan();

                        for (int i5 = 1; i5 <= 4; ++i5)
                        {
                            m[per[4]].xuan_zhuan();
                            for (int f1 = 1; f1 <= 2; ++f1)
                            {
                                m[per[0]].fan_zhuan();
                                for (int f2 = 1; f2 <= 2; ++f2)
                                {
                                    m[per[1]].fan_zhuan();
                                    for (int f3 = 1; f3 <= 2; ++f3)
                                    {
                                        m[per[2]].fan_zhuan();
                                        for (int f4 = 1; f4 <= 2; ++f4)
                                        {
                                            m[per[3]].fan_zhuan();
                                            for (int f5 = 1; f5 <= 2; ++f5)
                                            {
                                                m[per[4]].fan_zhuan();
                                                bool tmp = 1;
                                                {
                                                    tmp &= charu_mian(0, vtx, edges, m[per[0]]);
                                                    tmp &= charu_mian(1, vtx, edges, m[per[1]]);
                                                    tmp &= charu_mian(2, vtx, edges, m[per[2]]);
                                                    tmp &= charu_mian(3, vtx, edges, m[per[3]]);
                                                    tmp &= charu_mian(4, vtx, edges, m[per[4]]);
                                                }
                                                if (tmp)
                                                    return 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
    bool composeCube(vector<vector<string>> &shapes)
    {
        int jiao{};
        int leng{};
        vector<mian> m(6);
        int cc = 0;
        int n = shapes[0].size();
        man_leng = (1 << (n - 2)) << 1;
        for (auto &x : shapes)
        {
            jiao += x[0][0] == '1';
            jiao += x[0][n - 1] == '1';
            jiao += x[n - 1][0] == '1';
            jiao += x[n - 1][n - 1] == '1';
            for (int i = 1; i < n - 1; ++i)
            {
                leng += x[0][i] == '1';
                leng += x[n - 1][i] == '1';
                leng += x[i][0] == '1';
                leng += x[i][n - 1] == '1';
                m[cc].leng_up |= (x[0][i] == '1') ? (1 << i) : 0;
                m[cc].leng_down |= (x[n - 1][i] == '1') ? (1 << i) : 0;
                m[cc].leng_left |= (x[i][0] == '1') ? (1 << i) : 0;
                m[cc].leng_right |= (x[i][n - 1] == '1') ? (1 << i) : 0;
            }
            m[cc].jiao1 = x[0][0] == '1';
            m[cc].jiao2 = x[0][n - 1] == '1';
            m[cc].jiao3 = x[n - 1][0] == '1';
            m[cc].jiao4 = x[n - 1][n - 1] == '1';
            cc++;
        }
        if (jiao != 8)
            return false;
        if (leng != (12 * n - 24))
            return false;
        for (int i = 1; i <= 4; ++i)
        {
            m[0].xuan_zhuan();
            for (int j = 1; j <= 2; ++j)
            {
                m[0].fan_zhuan();
                vector<int> per = {1, 2, 3, 4, 5};
                vector<int> vtx(8, 0);
                vector<int> bian(12, 0);
                vtx[0] = m[0].jiao1;
                vtx[1] = m[0].jiao2;
                vtx[2] = m[0].jiao3;
                vtx[3] = m[0].jiao4;
                bian[0] = m[0].leng_up;
                bian[1] = m[0].leng_left;
                bian[2] = m[0].leng_right;
                bian[3] = m[0].leng_down;
                bool tmp;
                do
                {
                    tmp = check(per, m, vtx, bian);
                    if (tmp == 1)
                        return 1;
                } while (next_permutation(per.begin(), per.end()));
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> v{{"000", "110", "000"}, {"110", "011", "000"}, {"110", "011", "110"}, {"000", "010", "111"}, {"011", "111", "011"}, {"011", "010", "000"}};
    cout << s.composeCube(v);
}