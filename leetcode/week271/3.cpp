#include <bits/stdc++.h>

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

class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {
        auto alice = plants.begin();
        auto bob = plants.end() - 1;
        int nowa{capacityA};
        int nowb{capacityB};
        int cnt{};
        while (alice != bob && alice + 1 != bob)
        {
            if (nowa < *alice)
            {
                nowa = capacityA;
                cnt++;
            }
            if (nowb < *bob)
            {
                nowb = capacityB;
                cnt++;
            }
            nowa -= *alice;
            nowb -= *bob;
            alice++;
            bob--;
        }
        if (alice == bob)
        {
            cnt += (max(nowa, nowb) < *bob);
        }
        if (alice + 1 == bob)
        {
            cnt += nowa < *alice;
            cnt += nowb < *bob;
        }
        return cnt;
    }
};

int main()
{
    vector<int> v{2, 2, 5, 2, 2};
    Solution s;
    cout << s.minimumRefill(v, 5, 5);
}