#include <bits/stdc++.h>

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
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int ans{};
        while (tickets[k])
        {
            for (int i = 0; i < k; ++i)
            {
                if (tickets[i])
                    tickets[i]--, ans++;
            }
            tickets[k]--;
            ans++;
            for (int i = k + 1; i < tickets.size(); ++i)
            {
                if (tickets[i])
                    tickets[i]--, ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution ss;
    vector<int> t{2, 3, 2};
    cout << ss.timeRequiredToBuy(t, 2);
}