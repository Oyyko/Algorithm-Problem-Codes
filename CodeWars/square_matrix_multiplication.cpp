#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>> matrix_multiplication(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, size_t n)
{
    // TODO: Return the result of A × B in the form of an n × n matrix
    // NOTE: Please allocate and return matrix C
    std::vector<std::vector<int>> c;
    c.resize(n);
    for (auto &x : c)
    {
        x.resize(n);
    }
    printf("%d\n", 2);
    for (auto &x : c)
    {
        for (auto &y : x)
        {
            y = 0;
        }
    }
    printf("%d\n", 3);
    cout << c[0][0]<< endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                printf("%d %d %d\n", i, j, k);
                printf("%d\n", 888);
                c[i][j] += a[i][k] * b[k][j];
                printf("%d\n", 999);
            }
        }
    }
    return c;
}

int main()
{
    std::vector<std::vector<int>> a = {{1, 2}, {3, 2}};
    std::vector<std::vector<int>> b = {{3, 2}, {1, 1}};
    std::vector<std::vector<int>> c = matrix_multiplication(a, b, 2);
}