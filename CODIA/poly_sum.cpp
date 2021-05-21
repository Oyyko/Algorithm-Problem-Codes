#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct monomial
{
    int cof;
    int exp;
    monomial *next;
};

struct polynomial
{
    monomial *head;
};

// for every tuple<int,int> in this program, the first one is cof, second is exp
// so get<1>(x) return x.exp
bool cmp(tuple<int, int> x, tuple<int, int> y)
{
    return get<1>(x) > get<1>(y);
}

polynomial read(string line) //read from a line
{
    vector<tuple<int, int>> raw_in; // raw datd, disorder
    polynomial res;
    res.head = new monomial;
    res.head->next = nullptr;
    monomial *now_monomial = res.head;
    int _cof, _exp;
    stringstream ss;
    ss.str(line);
    while (ss >> _cof >> _exp)
    {
        raw_in.push_back(tuple<int, int>(_cof, _exp)); // read raw data in vector, so we can sort them
    }
    sort(raw_in.begin(), raw_in.end(), cmp); // sort by exp
    for (auto x : raw_in)
    {
        now_monomial->next = new monomial;
        now_monomial = now_monomial->next;
        now_monomial->cof = get<0>(x);
        now_monomial->exp = get<1>(x);
    } // build linked list

    return res;
}

void print_poly(polynomial p) // print
{
    monomial *itr = p.head->next;
    while (itr != nullptr)
    {
        if (itr->cof)
            cout << itr->cof << " " << itr->exp << " ";
        itr = itr->next;
    }
}

polynomial sum_poly(polynomial p1, polynomial p2) // return sum of p1 and p2
{
    monomial *itr1, *itr2;
    itr1 = p1.head->next;
    itr2 = p2.head->next;
    polynomial sum;
    sum.head = new monomial;
    sum.head->next = nullptr;
    monomial *itr3 = sum.head;
    while (itr1 != nullptr || itr2 != nullptr)
    {
        itr3->next = new monomial;
        itr3 = itr3->next;
        itr3->next = nullptr;
        if (itr1 == nullptr)
        {
            itr3->cof = itr2->cof;
            itr3->exp = itr2->exp;
            itr2 = itr2->next;
            continue;
        }
        if (itr2 == nullptr)
        {
            itr3->cof = itr1->cof;
            itr3->exp = itr1->exp;
            itr1 = itr1->next;
            continue;
        }
        if (itr1->exp < itr2->exp)
        {
            itr3->exp = itr2->exp;
            itr3->cof = itr2->cof;
            itr2 = itr2->next;
        }
        else if (itr1->exp > itr2->exp)
        {
            itr3->exp = itr1->exp;
            itr3->cof = itr1->cof;
            itr1 = itr1->next;
        }
        else
        {
            itr3->exp = itr2->exp;
            itr3->cof = itr2->cof + itr1->cof;
            itr2 = itr2->next;
            itr1 = itr1->next;
        }
    }
    return sum;
}

int main()
{
    string line;
    getline(cin, line);
    polynomial poly1, poly2;
    poly1 = read(line);
    getline(cin, line);
    poly2 = read(line);
    polynomial poly3;
    poly3 = sum_poly(poly1, poly2);
    print_poly(poly3);
}
