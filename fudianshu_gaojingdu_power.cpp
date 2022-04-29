// 【问题描述】有一个实数 R ( 0.0 < R < 99.999 ) , 要求写程序精确计算 R 的 n 次方。n 是整数并且 0 < n  <= 25。

// 【输入形式】每行包括一个实数R和指数n，中间以空格隔开，其中R最多10位，可能有前导0和尾0如0.00010，可能是整数如10，0 < n <= 25。

// 【输出形式】对于每行输入，要求输出相应的一行，该行是完全精确的 R 的 n 次方。输出需要去掉前导0和尾0，如.0001是合法输出。如果输出是整数，不能输出小数点。

// 【样例输入】

//   0.114514 3

//   0.1919810 3

//   100.0 4

// 【样例输出】

//   .001501674322828744

//   .007075786959929141

//   100000000




#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

class MyFloat
{
private:
    vector<int> digit;
    int left_shift;                       // 例如 123.34是12334左移2位 用来记录小数点的位置
    static constexpr int precision = 400; //整数 小数共多少位

public:
    MyFloat()
    {
        digit.resize(precision);
        left_shift = 0;
    }
    MyFloat(string &s)
    {
        digit.resize(precision);
        stack<int> ss;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '.')
            {
                left_shift = n - 1 - i;
                continue;
            }
            else
            {
                ss.push(s[i] - '0');
            }
        }
        int k = digit.size() - 1;
        while (!ss.empty())
        {
            digit[k--] = ss.top();
            ss.pop();
        }
    }
    friend ostream &operator<<(ostream &os, const MyFloat &f)
    {
        int point = MyFloat::precision - 1 - f.left_shift;
        int zhengshu_start{-1};
        for (int i = 0; i <= point; ++i)
        {
            if (f.digit[i] != 0)
            {
                zhengshu_start = i;
                break;
            }
        }
        if (zhengshu_start == -1)
            zhengshu_start = point + 1;
        int xiaoshu_end{-1};
        for (int i = MyFloat::precision - 1; i > point; --i)
        {
            if (f.digit[i] != 0)
            {
                xiaoshu_end = i;
                break;
            }
        }
        for (int i = zhengshu_start; i <= point; ++i)
        {
            os << f.digit[i];
        }
        if (xiaoshu_end != -1)
        {
            os << '.';
            for (int i = point + 1; i <= xiaoshu_end; ++i)
            {
                os << f.digit[i];
            }
        }

        return os;
    }
    MyFloat operator*(const MyFloat &rhs) const
    {
        MyFloat ans{};
        ans.left_shift = left_shift + rhs.left_shift;
        for (int i = precision - 1; i >= 0; --i)
            for (int j = precision - 1; j >= 0; --j)
            {
                int d = 1 + i + j - precision;
                if (d >= 0 && d < precision)
                    ans.digit[d] += digit[i] * rhs.digit[j];
            }
        for (int i = precision - 1; i >= 1; --i)
        {
            ans.digit[i - 1] += (ans.digit[i] / 10);
            ans.digit[i] %= 10;
        }
        return ans;
    }
    MyFloat pow(int p)
    {
        // cout << 111 << endl;
        MyFloat tmp = *this;
        // cout << 111 << endl;

        MyFloat ans{};
        ans.digit[precision - 1] = 1;
        do
        {
            if (p & 1)
            {
                ans = ans * tmp;
            }
            p >>= 1;
            tmp = tmp * tmp;
        } while (p);
        return ans;
    }
};

int main()
{
    string line;
    while (getline(cin, line))
    {
        stringstream ss{line};
        string num;
        int pow;
        ss >> num >> pow;
        MyFloat f{num};
        // cout << num << "   " << pow << endl;
        cout << f.pow(pow) << endl;
    }
}