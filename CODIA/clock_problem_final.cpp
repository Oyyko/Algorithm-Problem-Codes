#include <iostream>

using namespace std;

int main()
{
    int state[9];
    for (int i = 0; i < 9; ++i)
    {
        cin >> state[i];
    }
    int min_operation_times[9];    // the min operation time for the operation x
    int min_total_times{0xffffff}; // the min total ope times
    int now_total_times;           // the total time of a possible solution

    for (int o1 = 0; o1 < 4; ++o1) // you operate the operation 1 for o1 times
    {
        for (int o2 = 0; o2 < 4; ++o2) // as above
        {
            for (int o3 = 0; o3 < 4; ++o3)
            {
                for (int o4 = 0; o4 < 4; ++o4)
                {
                    for (int o5 = 0; o5 < 4; ++o5)
                    {
                        for (int o6 = 0; o6 < 4; ++o6)
                        {
                            for (int o7 = 0; o7 < 4; ++o7)
                            {
                                for (int o8 = 0; o8 < 4; ++o8)
                                {
                                    for (int o9 = 0; o9 < 4; ++o9)
                                    {
                                        if ((0 == (o1 + o2 + o4 + state[0]) % 4) && (0 == (o1 + o2 + o3 + o5 + state[1]) % 4) && (0 == (o2 + o3 + o6 + state[2]) % 4) && (0 == (o1 + o4 + o5 + o7 + state[3]) % 4) && (0 == (o1 + o3 + o5 + o7 + o9 + state[4]) % 4) && (0 == (o3 + o5 + o6 + o9 + state[5]) % 4) && (0 == (o4 + o7 + o8 + state[6]) % 4) && (0 == (o5 + o7 + o8 + o9 + state[7]) % 4) && (0 == (o6 + o8 + o9 + state[8]) % 4)) // check the given conditions
                                        {
                                            now_total_times = o1 + o2 + o3 + o4 + o5 + o6 + o7 + o8 + o9;
                                            if (now_total_times < min_total_times)
                                            {
                                                min_total_times = now_total_times;
                                                min_operation_times[0] = o1;
                                                min_operation_times[1] = o2;
                                                min_operation_times[2] = o3;
                                                min_operation_times[3] = o4;
                                                min_operation_times[4] = o5;
                                                min_operation_times[5] = o6;
                                                min_operation_times[6] = o7;
                                                min_operation_times[7] = o8;
                                                min_operation_times[8] = o9;
                                            } //update info
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // output answer
    for (int i = 0; i < 9; ++i)
    {
        while (min_operation_times[i])
        {
            cout << i + 1 << " ";
            min_operation_times[i]--;
        }
    }
}