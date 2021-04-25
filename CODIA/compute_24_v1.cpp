#include <iostream>
#include <cmath> // use fabs

using namespace std;

void search(int len, double *nums, bool &is_find) // search for the answer
// pass the answer to "main" by variable is_find
{
    double temp[4];
    if (len == 1) // only when the last number is 24, then the answer is YES
    {
        if (fabs(nums[0] - 24.0) < 1e-6)
        {
            is_find = true;
        }
        return;
    }
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            int k{1};
            // copy other nums
            for (int l = 0; l < len; ++l)
            {
                if (l != i && l != j)
                {
                    temp[k++] = nums[l];
                }
            }

            // pick two nums, compute them, then pick out them and put the computing answer of them to the nums
            // so that the size of nums will decrease one
            temp[0] = nums[i] + nums[j];
            search(len - 1, temp, is_find);

            temp[0] = nums[i] - nums[j];
            search(len - 1, temp, is_find);

            temp[0] = nums[j] - nums[i];
            search(len - 1, temp, is_find);

            temp[0] = nums[i] * nums[j];
            search(len - 1, temp, is_find);

            // attention: you cannot divide by zero
            if (nums[j] != 0)
            {

                temp[0] = nums[i] / nums[j];
                search(len - 1, temp, is_find);
            }
            if (nums[i] != 0)
            {

                temp[0] = nums[j] / nums[i];
                search(len - 1, temp, is_find);
            }
        }
    }
}

int main()
{
    double a[4];
    bool flag;
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    while (a[0] != 0 || a[1] != 0 || a[2] != 0 || a[3] != 0)
    {
        flag = false;
        search(4, a, flag);
        if (flag == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        cin >> a[0] >> a[1] >> a[2] >> a[3];
    }
}