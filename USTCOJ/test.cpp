#include <iostream>

using namespace std;

int Pre[10][1];

int main()
{
    cout << Pre[2][0] << "\n";
    Pre[1][0] += 1;
    Pre[1][1] += 1;
    cout << Pre[2][0] << "\n";
}