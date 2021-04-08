#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric> // to use std::iota

using namespace std;

// Solve: First, sort the words. Second, the shortest_prefix of a word can be fixed by its two(or one) neighbor(s). Third, because we need to print in the order of the input, so we just sort the indexes.

string greatest_common_prefix(string a, string b) // return greatest commnom prefix. For example, "abc" and "absss" will return "ab"
{
    int min_len = min(a.length(), b.length());
    for (int i = 0; i < min_len; ++i)
    {
        if (a[i] != b[i])
        {
            return a.substr(0, i);
        }
    }
    return a.substr(0, min_len);
}

template <typename T>
vector<size_t> sort_index(const vector<T> &v) // the i_th integer of the output vector will be the original index corresponding to the i_th element of the sorted v. IN SHORT, it will return the SORTED INDEX.
{
    vector<size_t> index(v.size());
    iota(index.begin(), index.end(), 0);

    stable_sort(index.begin(), index.end(), [&v](size_t i1, ssize_t i2) { return v[i1] < v[i2]; });
    return index;
}

int main()
{
    vector<string> words; // all the input words
    string one_word;
    while (getline(cin, one_word))
    {
        words.push_back(one_word);
    }                                                  // read in words
    vector<string> prefixs(words.size());              //prefix of the words
    vector<size_t> sorted_indexes = sort_index(words); // sorted indexes

    // boundary condition
    // we need the neighbor of the index but the first and last one has only one neighbor while other ones have 2 neighbors. So we deal with first and end specially.

    // first
    auto i = sorted_indexes.begin();
    prefixs[*i] = words[*i].substr(0, 1 + greatest_common_prefix(words[*i], words[*(i + 1)]).size());

    // middle
    for (i = i + 1; i != sorted_indexes.end() - 1; ++i)
    {
        prefixs[*i] = words[*i].substr(0, 1 + max(greatest_common_prefix(words[*i], words[*(i - 1)]).size(), greatest_common_prefix(words[*i], words[*(i + 1)]).size()));
    }

    // end
    prefixs[*i] = words[*i].substr(0, 1 + greatest_common_prefix(words[*i], words[*(i - 1)]).size());

    // output
    for (size_t i{0}; i < words.size(); ++i)
    {
        cout << words[i] << " " << prefixs[i] << endl;
    }
}