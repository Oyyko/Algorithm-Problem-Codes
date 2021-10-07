#include <iostream>
#include <vector>

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

class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
private:
    int last;

public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        if (Iterator::hasNext())
        {
            last = Iterator::next();
        }
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return last;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        if (Iterator::hasNext())
        {
            int x = last;
            last = Iterator::next();
            return x;
        }
        else
        {
            int x = last;
            last = -1;
            return x;
        }
    }

    bool hasNext() const
    {
        return (last != -1);
    }
};

int main()
{
}