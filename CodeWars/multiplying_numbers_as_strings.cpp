#include <iostream>
#include <string>
#include <vector>

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

string multiply(string a, string b)
{
    int la = a.size(), lb = b.size();
    vector<int> v(la + lb, 0);
    for (int i{}; i < la; ++i)
        for (int j{}; j < lb; ++j)
            v[i + j + 1] += (a[i] - '0') * (b[j] - '0');
    for (int k = la + lb - 1; k > 0; --k)
    {
        v[k - 1] += v[k] / 10;
        v[k] %= 10;
    }
    int i{};
    for (; i < la + lb && v[i] == 0; i++)
        ;
    if (i == la + lb)
        return "0";
    string ans{};
    for (; i < la + lb; ++i)
    {
        ans.push_back(v[i] + '0');
    }
    return ans;
}

int main()
{
    cout << multiply("12"s, "14"s);
}