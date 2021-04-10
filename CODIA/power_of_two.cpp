#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

const int max_size = 1005;
const int base = 100000000;

pair<int, int> full_adder(int x, int y); // return first=out, second=carry

class BigNum
{
private:
    vector<int> digit; // use base 10^8
public:
    BigNum();
    BigNum(int x);
    void print_big_num();
    int read_digit(int index);
    void change_digit(int num, int index);
    void left_shift(int i); // means multiply base
};

void BigNum::left_shift(int i)
{
    if (i == 0)
    {
        return;
    }
    auto itr = this->digit.end();
    while (*itr == 0)
    {
        itr--;
    }
    itr = itr + i;
    while ((itr - i != this->digit.begin()))
    {
        *itr = *(itr - i);
        itr--;
    }
    *itr = *(itr - i);
    itr--;
    while (itr != this->digit.begin())
    {
        *itr = 0;
        itr--;
    }
    *itr = 0;
}

int BigNum::read_digit(int index)
{
    return digit[index];
}

void BigNum::change_digit(int num, int index)
{
    digit[index] = num;
}

BigNum::BigNum()
{
    digit.resize(max_size);
}

BigNum::BigNum(int x)
{
    digit.resize(max_size);
    digit[0] = x;
}

pair<int, int> full_adder(int x, int y)
{
    pair<int, int> res;
    res.first = (x + y) % (base);
    res.second = (x + y) / base;
    return res;
}

BigNum big_num_add(BigNum x, BigNum y)
{
    int carry{0};
    int out;
    pair<int, int> temp;
    BigNum z;
    for (int i = 0; i < max_size; ++i)
    {
        temp = full_adder(x.read_digit(i), y.read_digit(i));
        out = temp.first;
        z.change_digit(out + carry, i);
        carry = temp.second;
    }
    return z;
}

void BigNum::print_big_num()
{
    auto itr = this->digit.end();
    itr--;
    while (*itr == 0)
    {
        itr--;
    }
    while (itr != this->digit.begin())
    {
        cout << *itr << setw(8) << setfill('0');
        itr--;
    }
    cout << *itr << endl;
}

template <typename M, M(mul)(M, M)>
M fast_power(M x, int k, M e) // x^k (e is identity)
{
    M ans = e;
    do
    {
        if (k & 1)
        {
            ans = mul(ans, x);
        }
        k >>= 1;
        x = mul(x, x);
    } while (k);
    return ans;
}

BigNum big_num_multiply_int(BigNum x, int n)
{
    BigNum res;
    BigNum e(0);
    if (n == 0)
    {
        return e;
    }
    res = fast_power<BigNum, big_num_add>(x, n, e);
    return res;
}

BigNum big_num_multiply(BigNum x, BigNum y)
{
    BigNum res(0);
    BigNum temp;
    int index;
    for (index = max_size - 1; y.read_digit(index) == 0; --index)
    {
    }
    for (auto i = 0; i <= index; ++i)
    {
        temp = big_num_multiply_int(x, y.read_digit(i));
        temp.left_shift(i);
        res = big_num_add(res, temp);
    }
    return res;
}

BigNum big_num_power_int(BigNum x, int n)
{
    BigNum e(1);
    return fast_power<BigNum, big_num_multiply>(x, n, e);
}

int main()
{
    // BigNum x(3);
    // x.print_big_num();
    // BigNum y(99999999);
    // BigNum z = big_num_add(x, y);
    // z.print_big_num();
    // BigNum a = big_num_multiply_int(x, 2);
    // a.print_big_num();
    // BigNum b = big_num_multiply(a, x);
    // b.print_big_num();
    // BigNum two(2);
    // BigNum ans = big_num_power_int(two, 10);
    // ans.print_big_num();

    int n;
    cin >> n;
    BigNum two(2);
    BigNum ans = big_num_power_int(two, n);
    ans.print_big_num();
}