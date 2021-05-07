#include <iostream>

using namespace std;

int mapp[55][55];
int color[55][55];

int number_of_rooms{0};
int max_room_size;
int now_room_size;
int room_size_of_color[2005];

void dfs(int i, int j)
{
    if (color[i][j])
    {
        return;
    }
    now_room_size++;
    color[i][j] = number_of_rooms;

    if ((mapp[i][j] & 1) == 0)
    {
        dfs(i, j - 1);
    }
    if ((mapp[i][j] & 2) == 0)
    {
        dfs(i - 1, j);
    }
    if ((mapp[i][j] & 4) == 0)
    {
        dfs(i, j + 1);
    }
    if ((mapp[i][j] & 8) == 0)
    {
        dfs(i + 1, j);
    }
}

int max_size2{1};
int which_wall_line;
int which_wall_colomn;
char which_wall_dirction;
int now_size2;
int m, n;

void search(int i, int j)
{
    int colorr = color[i][j];

    if (j + 1 <= m && color[i][j + 1] == colorr && (((mapp[i][j] >> 2) & 1) == 1))
    {
        now_size2 = room_size_of_color[colorr];
        if (now_size2 > max_size2)
        {
            which_wall_line = i;
            which_wall_colomn = j;
            max_size2 = now_size2;
            which_wall_dirction = 'E';
        }
        else if (now_size2 == max_size2)
        {
            if (j < which_wall_colomn)
            {
                which_wall_colomn = j;
                which_wall_dirction = 'E';
            }
            if (j == which_wall_colomn)
            {
                if (i > which_wall_line)
                {
                    which_wall_line = i;
                    which_wall_dirction = 'E';
                }
            }
        }
        else
        {
        }
    }

    if (i >= 2 && color[i - 1][j] == colorr && (((mapp[i][j] >> 1) & 1) == 1))
    {
        now_size2 = room_size_of_color[colorr];
        if (now_size2 > max_size2)
        {
            which_wall_line = i;
            which_wall_colomn = j;
            max_size2 = now_size2;
            which_wall_dirction = 'N';
        }
        else if (now_size2 == max_size2)
        {
            if (j < which_wall_colomn)
            {
                which_wall_colomn = j;
                which_wall_dirction = 'N';
            }
            if (j == which_wall_colomn)
            {
                if (i > which_wall_line)
                {
                    which_wall_line = i;
                    which_wall_dirction = 'N';
                }
            }
            if (i == which_wall_line && j == which_wall_colomn)
            {
                which_wall_dirction = 'N';
            }
        }
        else
        {
        }
    }

    if (j + 1 <= m && color[i][j + 1] != colorr)
    {
        now_size2 = room_size_of_color[color[i][j + 1]] + room_size_of_color[colorr];
        if (now_size2 > max_size2)
        {
            which_wall_line = i;
            which_wall_colomn = j;
            max_size2 = now_size2;
            which_wall_dirction = 'E';
        }
        else if (now_size2 == max_size2)
        {
            if (j < which_wall_colomn)
            {
                which_wall_colomn = j;
                which_wall_dirction = 'E';
            }
            if (j == which_wall_colomn)
            {
                if (i > which_wall_line)
                {
                    which_wall_line = i;
                    which_wall_dirction = 'E';
                }
            }
        }
        else
        {
        }
    }

    if (i >= 2 && color[i - 1][j] != colorr)
    {
        now_size2 = room_size_of_color[color[i - 1][j]] + room_size_of_color[colorr];
        if (now_size2 > max_size2)
        {
            which_wall_line = i;
            which_wall_colomn = j;
            max_size2 = now_size2;
            which_wall_dirction = 'N';
        }
        else if (now_size2 == max_size2)
        {
            if (j < which_wall_colomn)
            {
                which_wall_colomn = j;
                which_wall_dirction = 'N';
            }
            if (j == which_wall_colomn)
            {
                if (i > which_wall_line)
                {
                    which_wall_line = i;
                    which_wall_dirction = 'N';
                }
            }
            if (i == which_wall_line && j == which_wall_colomn)
            {
                which_wall_dirction = 'N';
            }
        }
        else
        {
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> mapp[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!color[i][j])
            {
                number_of_rooms++;
                now_room_size = 0;
                dfs(i, j);
                room_size_of_color[number_of_rooms] = now_room_size;
                max_room_size = max(max_room_size, now_room_size);
            }
        }
    }
    cout << number_of_rooms << endl;
    cout << max_room_size << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            search(i, j);
        }
    }
    cout << max_size2 << endl
         << which_wall_line << " " << which_wall_colomn << " " << which_wall_dirction << endl;
}