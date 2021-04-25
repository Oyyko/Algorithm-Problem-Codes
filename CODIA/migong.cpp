#include <iostream>

using namespace std;

char martix[105][105]; //save the data of map
bool color[105][105];
// if can be reached by start point, then color is 1
// so we can know whether A can reach B by just checking color[hb][lb]

void search(int i, int j, int size)
{
    // no beyond size
    if (i < 0 || j < 0)
    {
        return;
    }
    if (i >= size || j >= size)
    {
        return;
    }

    // cannot go through '#'
    if (martix[i][j] == '#')
    {
        return;
    }

    // if color is 1, no need to search twice
    if (color[i][j] == 1)
    {
        return;
    }

    //dfs
    color[i][j] = 1;
    search(i + 1, j, size);
    search(i, j + 1, size);
    search(i - 1, j, size);
    search(i, j - 1, size);
}

int main()
{
    int k;
    cin >> k;
    int n;
    int ha, hb, la, lb;
    while (k--)
    {
        cin >> n;
        getchar();

        // INIT
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                color[i][j] = 0;
            }
        }

        // READ IN
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                martix[i][j] = getchar();
            }
            getchar();
        }
        cin >> ha >> la >> hb >> lb;

        // SPECIAL CASE
        if (martix[ha][la] == '#' || martix[hb][lb] == '#')
        {
            cout << "NO" << endl;
            continue;
        }

        // DFS
        search(ha, la, n);
        if (color[hb][lb] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
