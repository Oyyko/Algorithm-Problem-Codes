#include <iostream>
#include <random>
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

class Solution
{
public:
    int minimumNumbers(int num, int k)
    {
        if (num == 0)
            return 0;
        if (num % 10 == k)
            return 1;
        if (num >= 1 && num <= 9)
        {
            if (num == k)
                return 1;
            if (num == 2 * k)
                return 2;
            if (num == 3 * k)
                return 3;
            if (num == 4 * k)
                return 4;
            if (k == 1)
                return num;
            return -1;
        }
        if (num <= 2 * k)
        {
            if (num == 10 + k)
                return 1;
            if (num == 2 * k)
                return 2;
            if (num == k)
                return 1;
            return -1;
        }
        if (num == 10)
        {
            if (k == 1)
                return 10;
            if (k == 2)
                return 5;
            if (k == 5)
                return 2;
        }
        if (num % 2 == 0)
        {
            if ((k * 2) % 10 == num % 10)
                return 2;
            if (k == 1)
                return num;
            return -1;
        }
        if (k == 0)
        {
            if (num % 10 == 0)
                return 1;
            return -1;
        }
        if (k % 2 == 0)
            return -1;
        return 3;
    }
};

int main()
{
}