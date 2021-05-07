#include <iostream>
#include <cstring> // memset

using namespace std;

const int max_size = 80;
int w, h;
char mp[max_size][max_size];                        //map
bool visited[max_size][max_size];                   // mark if (x,y) is visvited;
int dis[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // four different direction

void search(int now_x, int now_y, int end_x, int end_y, int now_step, int &min_step, int last_direction)
//when using this func, you should set last_direction=-1 and now_step=0
{
    if (now_step >= min_step)
    {
        return;
    }
    if (now_x == end_x && now_y == end_y)
    {
        min_step = min(min_step, now_step);
        return;
    }
    for (int i = 0; i <= 3; ++i)
    {
        int next_x = now_x + dis[i][0];
        int next_y = now_y + dis[i][1];
        if ((next_x > -1 && next_y > -1 && next_x < w + 2 && next_y < h + 2) && ((visited[next_y][next_x] == false && mp[next_y][next_x] == ' ') || (next_x == end_x && next_y == end_y && mp[next_y][next_x] == 'X')))
        {
            visited[next_y][next_x] = true;
            if (i == last_direction)
            {
                search(next_x, next_y, end_x, end_y, now_step, min_step, i);
            }
            else
            {
                search(next_x, next_y, end_x, end_y, now_step + 1, min_step, i);
            }
            visited[next_y][next_x] = false;
        }
    }
}

int main()
{
    int board_id{};
    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
        {
            break;
        }
        board_id++;
        cout << "Board #" << board_id << ":" << endl;

        // add inner space
        for (int i = 0; i < max_size; ++i)
        {
            mp[0][i] = mp[i][0] = ' ';
        }

        //read in map
        for (int i = 1; i <= h; ++i)
        {
            getchar(); //deal with '\n'
            for (int j = 1; j <= w; ++j)
            {
                mp[i][j] = getchar();
            }
        }

        // add outer space
        for (int i = 0; i <= w; ++i)
        {
            mp[h + 1][i + 1] = ' ';
        }
        for (int i = 0; i <= h; ++i)
        {
            mp[i + 1][w + 1] = ' ';
        }

        int start_x, start_y;
        int end_x, end_y;
        int pair_id{};
        int min_steps;
        while ((cin >> start_x >> start_y >> end_x >> end_y) && (start_x > 0))
        {
            pair_id++;
            cout << "Pair " << pair_id << ": ";
            min_steps = 0xfffff;
            memset(visited, false, sizeof(visited));
            search(start_x, start_y, end_x, end_y, 0, min_steps, -1);

            if (min_steps == 0xfffff)
            {
                cout << "impossible." << endl;
            }
            else
            {
                cout << min_steps << " segments." << endl;
            }
        }
        cout << endl;
    }
}