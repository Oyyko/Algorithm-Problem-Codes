#include <iostream>
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

#include <mutex>
#include <condition_variable>
#include <thread>

class Foo
{
public:
    condition_variable cv;
    mutex mtx;
    int k = 0;
    Foo() = default;

    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        k = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {

        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]()
                { return k == 1; });
        printSecond();
        k = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird)
    {

        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]()
                { return k == 2; });
        printThird();
    }
};

int main()
{
    Foo f;
    thread t1(f.first(), &f);
    t1.join();
}