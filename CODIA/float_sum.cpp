#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

const int max_size = 1005;  // max number of digits
const int base = 100000000; // base 2, base 10 is familar. But now we are going to use base 10^8

pair<int, int> full_adder(int x, int y); // return first=out, second=carry

class BigNum
{
private:
    vector<int> digit; // use base 10^8
public:
    BigNum();
    BigNum(int x); // constructor: construct a BigNum with value x, x < 10^8
    void read_from_string(string s);
    void print_big_num(); // print
    int read_digit(int index);
    void change_digit(int num, int index);
    void left_shift(int i); // means multiply base
    void print_float_part();
};

void BigNum::print_float_part()
{
    stringstream ss;
    auto itr = digit.begin() + 13;
    itr--;
    while (itr != this->digit.begin())
    {
        ss << setw(8) << setfill('0') << *itr;
        itr--;
    }
    ss << left << *itr;
    string s = ss.str();
    for (auto x = s.end() - 1; *x == '0';)
    {
        s.pop_back();
        x = s.end() - 1;
    }
    cout << s;
}

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

// template for fast power algorithm
// can be used to calculate power with mul, or calculate mul with add
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

int int_mul(int a, int b)
{
    return a * b;
}

void BigNum::read_from_string(string s)
{
    int cnt_if_next_digit{0}; // when this is 8, it's time to move to the next digit
    int now_digit_num{0};
    int now_digit_index{0};
    for (int i = s.size() - 1; i >= 0; --i)
    {
        now_digit_num += (s[i] - '0') * fast_power<int, int_mul>(10, cnt_if_next_digit, 1);
        cnt_if_next_digit++;
        if (cnt_if_next_digit == 8)
        {
            cnt_if_next_digit = 0;
            digit[now_digit_index] = now_digit_num;
            now_digit_index++;
            now_digit_num = 0;
        }
    }
    digit[now_digit_index] = now_digit_num;
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

pair<int, int> full_adder(int x, int y, int carryin) // a simple full_adder. in order to deal with add BigNums
{
    pair<int, int> res;
    res.first = (x + y + carryin) % (base);
    res.second = (x + y + carryin) / base;
    return res;
}

BigNum big_num_add(BigNum x, BigNum y) // like a pupil will learn in school
{
    int carryout{0};
    int out;
    pair<int, int> temp;
    BigNum z;
    for (int i = 0; i < max_size; ++i)
    {
        temp = full_adder(x.read_digit(i), y.read_digit(i), carryout);
        out = temp.first;
        z.change_digit(out, i);
        carryout = temp.second;
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
        if (itr == this->digit.begin() && (*itr) == 0)
        {
            cout << "0";
            return;
        }
    }
    while (itr != this->digit.begin())
    {
        cout << *itr << setw(8) << setfill('0');
        itr--;
    }
    cout << *itr;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    BigNum int1, int2, float1, float2;
    BigNum int3, float3;

    for (int i = 1; i <= n; ++i)
    {
        string int_part, float_part;
        getline(cin, int_part, '.');
        getline(cin, float_part);
        int1.read_from_string(int_part);
        stringstream ss1;
        ss1 << left << setw(104) << setfill('0') << float_part;
        string temp_s1 = ss1.str();
        float1.read_from_string(temp_s1);

        getline(cin, int_part, '.');
        getline(cin, float_part);
        int2.read_from_string(int_part);
        stringstream ss2;
        ss2 << left << setw(104) << setfill('0') << float_part;
        string temp_s2 = ss2.str();
        float2.read_from_string(temp_s2);

        int3 = big_num_add(int1, int2);
        float3 = big_num_add(float1, float2);
        if (float3.read_digit(13) == 1)
        {
            int3 = big_num_add(int3, BigNum(1));
        }
        float3.change_digit(0, 13);
        int3.print_big_num();
        cout << ".";
        float3.print_float_part();
        string temp_s;
        if (i != n)
        {
            getline(cin, temp_s); // read empty line
            cout << endl;
        }
    }
}
