#include "../base.hpp"
#include <iterator>
#include <set>
#include <vector>

int main() {
  multiset<int> s;
  s.insert(5);
  s.insert(3);
  cout << distance(s.upper_bound(1), s.end());
}