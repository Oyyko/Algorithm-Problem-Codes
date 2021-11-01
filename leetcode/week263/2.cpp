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

class Bank
{
private:
    vector<long long> ba;
    int n;
    bool check(int x)
    {
        if (x <= n && x >= 1)
        {
            return true;
        }
        return false;
    }
    bool check(int acc, long long m)
    {
        return ba[acc] >= m;
    }

public:
    Bank(vector<long long> &balance)
    {
        n = balance.size();
        ba.resize(balance.size() + 1);
        for (int i = 0; i < balance.size(); ++i)
        {
            ba[i + 1] = balance[i];
        }
    }

    bool transfer(int account1, int account2, long long money)
    {
        bool flag = true;
        flag &= check(account1);
        flag &= check(account2);
        if (!flag)
        {
            return flag;
        }
        flag &= check(account1, money);
        if (!flag)
        {
            return flag;
        }
        ba[account1] -= money;
        ba[account2] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        bool flag = true;
        flag &= check(account);
        if (!flag)
        {
            return flag;
        }
        ba[account] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {

        bool flag{true};
        flag &= check(account);
        if (!flag)
        {
            return flag;
        }
        flag &= check(account, money);
        if (!flag)
        {
            return false;
        }
        ba[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

int main()
{
    vector<long long> s{10, 100, 20, 50, 30};
    Bank b{s};
    cout << b.withdraw(3, 10);
    cout << b.transfer(5, 1, 20);
    cout << b.deposit(5, 20);
    cout << b.transfer(3, 4, 15);
    cout << b.withdraw(10, 50);
}