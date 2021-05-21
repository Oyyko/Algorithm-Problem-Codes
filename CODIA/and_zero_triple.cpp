#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int count(vector<int> &A)
    {
        int res{};
        map<int, int> store;
        int len = A.size();
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                int temp = A[i] & A[j];
                store[temp]++;
            }
        }
        for (auto itr = store.begin(); itr != store.end(); ++itr)
        {
            if (itr->first == 0)
            {
                res += len * (itr->second);
                continue;
            }
            for (int i = 0; i < len; ++i)
            {
                if ((A[i] & itr->first) == 0)
                {
                    res += itr->second;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> x;
    getchar();
    char tmp_char;
    int tmp_int;
    cin >> tmp_int;
    tmp_char = getchar();
    while (tmp_char == ',')
    {
        x.push_back(tmp_int);
        cin >> tmp_int;
        tmp_char = getchar();
    }
    x.push_back(tmp_int);

    cout << s.count(x);
}