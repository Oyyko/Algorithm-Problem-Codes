#include <iostream>
#include <ctime>
using namespace std;

inline int must_times(int state_now) // when state is state_now, how many operation times need to make the state to be 0
{
    if (state_now == 0)
    {
        return 0;
    }
    return 4 - state_now;
}

int main()
{
    clock_t s, e;
    s = clock();
    int state[9]; // state of all the clocks.
    // state[0] for clock A
    // state[1] for clock B
    // the rest is same
    // 0 as 12hour, 1 as 3hour, 2 as 6hour, 3 as 9hour.
    // Our goal is to make all the clock to the state 0.

    for (int i = 0; i < 9; ++i)
    {
        cin >> state[i];
    }
    const char *operations[9] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
    int operation_times[9]; // do "operation[m]" for "operation_times[m]" times.

    int now_total_times;
    int min_total_times{0xffffff};
    int min_operation_times[9];

    for (operation_times[0] = 0; operation_times[0] <= 3; ++operation_times[0])
    {
        for (operation_times[1] = 0; operation_times[1] <= 3; ++operation_times[1])
        {
            for (operation_times[2] = 0; operation_times[2] <= 3; ++operation_times[2])
            {
                now_total_times = 0;

                for (int m = 0; m <= 2; ++m)
                {
                    for (int k = 0; operations[m][k]; ++k)
                    {
                        state[operations[m][k] - 'A'] += operation_times[m];
                        state[operations[m][k] - 'A'] = state[operations[m][k] - 'A'] % 4;
                    }
                    now_total_times += operation_times[m];
                    if (now_total_times >= min_total_times)
                    {
                        break;
                    }
                } // update state info and total times info

                operation_times[3] = must_times(state[0]); //only operation 3 can change clock 'A'
                operation_times[4] = must_times(state[1]); //only operation 4 can change clock 'B'
                operation_times[5] = must_times(state[2]); //only operation 5 can change clock 'C'

                for (int m = 3; m <= 5; ++m)
                {
                    for (int k = 0; operations[m][k]; ++k)
                    {
                        state[operations[m][k] - 'A'] += operation_times[m];
                        state[operations[m][k] - 'A'] = state[operations[m][k] - 'A'] % 4;
                    }
                    now_total_times += operation_times[m];
                    if (now_total_times >= min_total_times)
                    {
                        break;
                    }
                } // update state info and total times info

                operation_times[6] = must_times(state[3]); //only operation 6 can change clock 'D'

                for (int m = 6; m <= 6; ++m)
                {
                    for (int k = 0; operations[m][k]; ++k)
                    {
                        state[operations[m][k] - 'A'] += operation_times[m];
                        state[operations[m][k] - 'A'] = state[operations[m][k] - 'A'] % 4;
                    }
                    now_total_times += operation_times[m];
                    if (now_total_times >= min_total_times)
                    {
                        break;
                    }
                } // update state info

                //only operation 8 can change clock 'E' and clock 'F'
                //so E and F must be at the same state.
                if (state[4] != state[5])
                {
                    break;
                }
                operation_times[8] = must_times(state[5]);

                for (int m = 8; m <= 8; ++m)
                {
                    for (int k = 0; operations[m][k]; ++k)
                    {
                        state[operations[m][k] - 'A'] += operation_times[m];
                        state[operations[m][k] - 'A'] = state[operations[m][k] - 'A'] % 4;
                    }
                    now_total_times += operation_times[m];
                    if (now_total_times >= min_total_times)
                    {
                        break;
                    }
                } // update state info

                if (state[6] != state[7] || state[6] != state[8])
                {
                    break;
                }
                operation_times[7] = must_times(state[6]);

                now_total_times += operation_times[7];
                if (now_total_times >= min_total_times)
                {
                    break;
                }

                min_total_times = now_total_times;
                for (int i = 0; i < 9; ++i)
                {
                    min_operation_times[i] = operation_times[i];
                }
            }
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        while (min_operation_times[i])
        {
            cout << i + 1 << " ";
            min_operation_times[i]--;
        }
    }
    e = clock();
    cout << e - s;
}