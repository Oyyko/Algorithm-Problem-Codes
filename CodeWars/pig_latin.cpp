#include <iostream>
#include <string>
#include <vector>

std::string change_word(const std::string &str, int l, int r) //[l,r]
{
    std::string s{};
    if (l >= r)
    {
        if (str[l] == '.' || str[l] == ',' || str[l] == '!' || str[l] == '?')
        {
            return std::string{str[l]};
        }
        return std::string{std::string{str[l]} + std::string{"ay"}};
    }
    s.resize(r - l + 1 + 2);
    for (int i = 0; i < r - l; ++i)
    {
        s[i] = str[l + i + 1];
    }
    s[r - l] = str[l];
    s[r - l + 1] = 'a';
    s[r - l + 2] = 'y';
    return s;
}

std::string pig_it(std::string str)
{
    std::string ans{};
    int last_space_loc{-1};

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == ' ')
        {
            ans += change_word(str, last_space_loc + 1, i - 1);
            ans += std::string{" "};
            last_space_loc = i;
        }
    }
    ans += change_word(str, last_space_loc + 1, str.size() - 1);
    return ans;
}

int main()
{
    std::string s;
    std::getline(std::cin, s);
    std::cout << pig_it(s);
}

/*

regex reg(("(\\w)(\\w*)(\\s|$)"));
    return regex_replace(Z, reg, "$2$1ay$3");


    (\w)(\w*)(\s|$)
    $2$1ay$3


*/