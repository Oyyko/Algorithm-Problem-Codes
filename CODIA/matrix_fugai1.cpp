#include <iostream>
#include <cstring> // memset

using namespace std;

const int MAX_LEN{15};

int min_area[(1 << MAX_LEN)]; //min_area[x] where x represent the state of covering.
// for example, point 1 and 3 is covered , 2,4,5 is not covered, then the state is 01011
// 0 as covered, 1 as not covered
// min_area[x] means if state is x, we STILL need how many area to cover all.

int point_x[15];
int point_y[15];
int total_points_num;

bool between(int a, int b, int c) // return true if and only if c is in [a,b]
{
    return (c >= a && c <= b) || (c >= b && c <= a);
}

int area(int i, int j) //compute area, note the matrix cannot be a line so for point_x[i]==point_x[j] we should return abs(point_y[i]-point_y[j])
{
    int dx = abs(point_x[i] - point_x[j]);
    int dy = abs(point_y[i] - point_y[j]);

    if (!dx)
    {
        return dy;
    }
    if (!dy)
    {
        return dx;
    }

    return dx * dy;
}

int search(int state)
{
    int next_state;
    int now_area;
    if (min_area[state] >= 0) //solved
    {
        return min_area[state];
    }
    if (state == 0) // all covered
    {
        return 0;
    }
    min_area[state] = 0xfffff; //initial

    for (int i = 0; i < total_points_num; ++i)
    {
        if (state & (1 << i)) // if point i is not covered
        {
            for (int j = 0; j < total_points_num; ++j)
            {
                if (i != j)
                {
                    next_state = state & (~((1 << i) | (1 << j))); // let i and j be covered
                    for (int k = 0; k < total_points_num; ++k)
                    {
                        if (between(point_x[i], point_x[j], point_x[k]) && between(point_y[i], point_y[j], point_y[k]))
                        {
                            next_state &= (~(1 << k));
                        }
                    } // if k is in the rectangle (i,j) then k will be covered too.
                    now_area = area(i, j) + search(next_state);
                    if (now_area < min_area[state])
                    {
                        min_area[state] = now_area;
                    }
                }
            }
        }
    }
    return min_area[state];
}

int main()
{
    cin >> total_points_num;
    while (total_points_num)
    {
        for (int i = 0; i < total_points_num; ++i)
        {
            cin >> point_x[i];
            cin >> point_y[i];
        }

        memset(min_area, -1, sizeof(min_area));              // -1 as not solved yet
        min_area[0] = 0;                                     // if all are covered, then STILL need 0 area to cover all
        cout << search((1 << total_points_num) - 1) << endl; // search start at all are not covered

        cin >> total_points_num;
    }
}