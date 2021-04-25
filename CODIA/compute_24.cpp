#include <iostream>
#include <set>

using namespace std;

bool is_equal(double x, double y)
{
    if ((x - y) <= 1e-9 && (y - x) <= 1e-9)
    {
        return 1;
    }
    return 0;
}

bool is_equal(int x, int y)
{
    return x == y;
}

void search(multiset<double> &nums, bool &flag)
{
    cout << "nums now: ";
    for (auto x : nums)
    {
        cout << x << ", ";
    }
    cout << endl;
    if (nums.empty())
    {
        return;
    }
    if (nums.size() == 1 && nums.find(24.0) == nums.end())
    {
        return;
    }
    if (nums.find(24.0) != nums.end())
    {
        flag = true;
        return;
    }
    for (auto ii = nums.begin(); ii != nums.end(); ++ii)
    {
        for (auto jj = nums.begin(); jj != nums.end(); ++jj)
        {
            if (ii == jj)
            {
                continue;
            }
            auto i = *ii;
            auto j = *jj;
            cout << i << endl
                 << &i << endl
                 << j << endl
                 << &j;
            nums.erase(ii);
            nums.erase(jj);
            printf("erased \n");

            cout << i << "+" << j << endl;
            nums.insert(i + j);
            search(nums, flag);
            if (flag == true)
            {
                return;
            }
            nums.erase(i + j);

            cout << i << "-" << j << endl;
            nums.insert(i - j);
            search(nums, flag);
            if (flag == true)
            {
                return;
            }
            nums.erase(i - j);

            cout << i << "*" << j << endl;
            nums.insert(i * j);
            search(nums, flag);
            if (flag == true)
            {
                return;
            }
            nums.erase(i * j);

            cout << i << "/" << j << endl;
            nums.insert(i / (j + 0.0));
            search(nums, flag);
            if (flag == true)
            {
                return;
            }
            nums.erase(i / (j + 0.0));

            printf("%d\n", 999);
            nums.insert(i);
            nums.insert(j);
            cout << "nums now2: ";
            for (auto x : nums)
            {
                cout << x << ", ";
            }
            cout << endl;
        }
    }
}

int main()
{
    bool flag{false};
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    multiset<double> nums;
    while ((!a && !b && !c && !d) == false)
    {
        nums.clear();
        nums.insert(a);
        nums.insert(b);
        nums.insert(c);
        nums.insert(d);
        search(nums, flag);
        cin >> a >> b >> c >> d;
    }
    cout << flag;
}
