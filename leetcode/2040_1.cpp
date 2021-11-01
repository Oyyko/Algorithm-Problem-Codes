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
private:
    typedef LL long long;
    vector<int> A, B;

    LL f(LL mm)
    {
        LL ret = 0;
        for (LL x : A)
        {
            if (x > 0)
            {
                if (x * B[0] > mm)
                    continue;
                int head = 0, tail = B.size() - 1;
                while (head < tail)
                {
                    int mid = (head + tail + 1) >> 1;
                    if (x * B[mid] <= mm)
                        head = mid;
                    else
                        tail = mid - 1;
                }
                ret += head + 1;
            }
            else if (x < 0)
            {
                if (x * B[B.size() - 1] > mm)
                    continue;
                int head = 0, tail = B.size() - 1;
                while (head < tail)
                {
                    int mid = (head + tail) >> 1;
                    if (x * B[mid] <= mm)
                        tail = mid;
                    else
                        head = mid + 1;
                }
                ret += B.size() - head;
            }
            else if (mm >= 0)
                ret += B.size();
        }
        return ret;
    }

public:
    LL kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, LL k)
    {
        A = nums1;
        B = nums2;
        LL head = -1e11, tail = 1e11;
        while (head < tail)
        {
            LL mid = (head + tail) >> 1;
            LL x = f(mid);
            if (x >= k)
                tail = mid;
            else
                head = mid + 1;
        }
        return head;
    }
};

int main()
{
}