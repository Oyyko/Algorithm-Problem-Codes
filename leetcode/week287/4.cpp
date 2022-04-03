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

class Encrypter
{
public:
    unordered_map<char, string> mp;
    unordered_map<string, int> cnt;
    Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary)
    {
        int n = keys.size();
        for (int i{}; i < n; ++i)
        {
            mp[keys[i]] = values[i];
        }
        for (auto &s : dictionary)
        {
            cnt[encrypt(s)]++;
        }
    }

    string encrypt(string word1)
    {
        string ans{};
        for (auto &c : word1)
        {
            ans += mp[c];
        }
        return ans;
    }

    int decrypt(string word2)
    {
        if (cnt.find(word2) == cnt.end())
            return 0;
        return cnt[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */

int main()
{
}