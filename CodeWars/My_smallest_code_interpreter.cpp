#include <bits/stdc++.h>

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

std::string brainLuck(const std::string &code, const std::string &input)
{
    unsigned char num[30000] = {0};
    unsigned char *p = num;
    std::string ans{};
    int input_reader{};
    std::unordered_map<int, int> l2r{}, r2l{};
    stack<pair<int, int>> s;
    for (int i = 0, _ = code.size(); i < _; ++i)
    {
        char x = code[i];
        if (x == '[')
        {
            s.push({0, i});
        }
        else if (x == ']')
        {
            auto [_, l] = s.top();
            s.pop();
            l2r[l] = i;
            r2l[i] = l;
        }
    }
    for (int i = 0, _ = code.size(); i < _; ++i)
    {
        char x = code[i];
        // cout << x << " " << (int)*p << endl;
        switch (x)
        {
        case '>':
            p++;
            break;
        case '<':
            p--;
            break;
        case '+':
            (*p)++;
            break;
        case '-':
            (*p)--;
            break;
        case '.':
            ans.push_back(*p);
            break;
        case ',':
            (*p) = input[input_reader++];
            break;
        case '[':
            if (*p == 0)
            {
                i = l2r[i];
            }
            break;
        case ']':
            if (*p != 0)
            {
                i = r2l[i];
            }
            break;

        default:
            break;
        }
    }
    return ans;
}

int main()
{
    string tw{"LOVE"};
    tw.append(1, (char)0);
    cout << brainLuck(",[.[-],]", tw);
}