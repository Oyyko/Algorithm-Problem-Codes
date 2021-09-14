#include <iostream>
#include <vector>
#include <tuple>

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

using namespace std;

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr)
    {
        vector<int> is_deleted;

        is_deleted.resize(arr.size());
        bool flag{false};
        for (int i = 0; i < arr.size(); ++i)
        {
            is_deleted[i] = 0;
        }
        // cout << "XXX" << is_confilct(arr, 1, 2) << "XXX";
    check:
        flag = false;

        for (int i = 0; i < arr.size() - 1; ++i)
        {
            // cout << i;
            if (!is_deleted[i])
            {
                int r = i + 1;
                while (r < arr.size() && is_deleted[r] == 1)
                {
                    r++;
                }
                // cout << "\ni:" << i << " r:" << r << "\n";
                if (is_confilct(arr, i, r))
                {
                    flag = true;
                    is_deleted[i] = is_deleted[r] = 1;
                    continue;
                }
            }
        }
        // cout << "flag:" << flag << "PPP";
        if (flag)
        {
            // cout << "QQQQ";
            goto check;
        }
        vector<string> ans;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (!is_deleted[i])
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
    static bool is_confilct(const std::vector<std::string> &arr, int l, int r)
    {
        if (r == arr.size())
            return false;
        if (arr[l] == "WEST"s && arr[r] == "EAST"s)
        {
            return true;
        }

        if (arr[l] == "EAST"s && arr[r] == "WEST"s)
        {
            return true;
        }

        if (arr[l] == "NORTH"s && arr[r] == "SOUTH"s)
        {
            return true;
        }

        if (arr[l] == "SOUTH"s && arr[r] == "NORTH"s)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    vector<string> arr;
    arr.push_back("NORTH"s);
    arr.push_back("NORTH"s);
    arr.push_back("SOUTH"s);
    arr.push_back("EAST"s);
    arr.push_back("WEST"s);
    arr.push_back("SOUTH"s);
    arr.push_back("EAST"s);
    DirReduction d;
    pr(d.dirReduc(arr));
}
