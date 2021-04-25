#include <iostream>

using namespace std;

int room[55][55];
int color[55][55];
int number_of_rooms{0};
int max_room_size{0};

void search(int i, int j, int &now_room_size) // search room (i,j)
{
    if (color[i][j]) // if searched, then skip
    {
        return;
    }
    now_room_size++;               // maintain size
    color[i][j] = number_of_rooms; // coloring

    // different walls
    if (0 == (room[i][j] & 1))
    {
        search(i, j - 1, now_room_size);
    }

    if (0 == (room[i][j] & 2))
    {
        search(i - 1, j, now_room_size);
    }

    if (0 == (room[i][j] & 4))
    {
        search(i, j + 1, now_room_size);
    }

    if (0 == (room[i][j] & 8))
    {
        search(i + 1, j, now_room_size);
    }
}

int main()
{

    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> room[i][j];
        }
    }

    int now_room_size;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (color[i][j] == 0)
            {
                number_of_rooms++;
                now_room_size = 0;
                search(i, j, now_room_size);
                max_room_size = max(max_room_size, now_room_size);
            }
        }
    }
    cout << number_of_rooms << endl
         << max_room_size << endl;

    return 0;
}