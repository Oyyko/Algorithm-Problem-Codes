#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string bi_search_in_dic(vector<pair<string, string>> &dic, vector<pair<string, string>>::iterator left, vector<pair<string, string>>::iterator right, string &foreign_word)
// search the dic to find the corresponding english word in time O(log n). When you use this function, provide dic.begin() as left and dic.end() as right. It will return the english_word. If not found, return "eh"s.
{
    if (right - left >= 0)
    {
        auto mid = left + (right - left) / 2;
        if ((*mid).first == foreign_word)
        {
            return (*mid).second;
        }
        if ((*mid).first > foreign_word)
        {
            return bi_search_in_dic(dic, left, mid - 1, foreign_word);
        }
        return bi_search_in_dic(dic, mid + 1, right, foreign_word);
    }
    return "eh"s;
}

int main()
{
    vector<pair<string, string>> dic; // first(key) is foreign, second(value) is english
    string line;                      //read line which contain dic info(one line contain one english and one foreign words)
    string foreign_word, english_word;
    while (getline(cin, line)) //read input, generate dic
    {
        if (line[0] < 'a' || line[0] > 'z')
        {
            break;
        }
        istringstream iss(line);
        iss >> english_word >> foreign_word;
        dic.push_back(make_pair(foreign_word, english_word));
    }
    // sort the dictionary using key(foreign word) so that binary search is possible
    sort(dic.begin(), dic.end());

    string foreign_word_to_translate;
    while (getline(cin, foreign_word_to_translate))
    {
        if (foreign_word_to_translate[0] < 'a' || foreign_word_to_translate[0] > 'z')
        {
            break;
        } //break the last empty line in input
        cout << bi_search_in_dic(dic, dic.begin(), dic.end(), foreign_word_to_translate) << endl;
    }
}