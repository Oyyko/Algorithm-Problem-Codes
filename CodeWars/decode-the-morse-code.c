#include <stdlib.h>
#include <stdio.h>

const char *morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};
const char *ascii[55] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", "?", "'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@", "SOS"};

char *decode_morse(const char *morse_code)
{
    char *s = (char *)malloc(sizeof(char) * 4000);
    char *s1 = s;
    char *p = morse_code;
    char *pp = morse_code;
    while (*p)
    {
        if (*p == ' ')
        {

            for (int i = 0; i < 55; ++i)
            {
                char *test = morse[i];
                char *test2 = pp;
                int flag = 1;
                while (*test && *test2 && test2 != p)
                {
                    if (*test != *test2)
                        flag = 0;
                    // printf("i: %d,pp:%c,p:%c,test:%c,test2:%c\n", i, *pp, *p, *test, *test2);
                    test++;
                    test2++;
                }
                int fflag = flag;
                if (*test != *test2)
                    flag = 0;
                if (fflag && *test == '\0' && *test2 == ' ')
                    flag = 1;
                if (flag)
                {
                    // printf("FLAGGGGGG i: %d,pp:%c,p:%c,test:%c,test2:%c\n", i, *pp, *p, *test, *test2);
                    *s1++ = *(ascii[i]);
                    if (i == 54)
                    {
                        *s1++ = *(ascii[i] + 1);
                        *s1++ = *(ascii[i] + 2);
                    }
                    break;
                }
            }
            pp = p + 1;
            if (*(p + 1) == ' ' && *(p + 2) == ' ')
            {
                *s1++ = ' ';
            }
        }
        p++;
    }
    for (int i = 0; i < 55; ++i)
    {
        char *test = morse[i];
        char *test2 = pp;
        int flag = 1;
        while (*test && *test2 && test2 != p)
        {
            if (*test != *test2)
                flag = 0;
            // printf("AAA i: %d,pp:%c,p:%c,test:%c,test2:%c\n", i, *pp, *p, *test, *test2);
            test++;
            test2++;
        }
        if (*test != *test2)
            flag = 0;
        if (flag)
        {
            // printf("FLAGGGGGG i: %d,pp:%c,p:%c,test:%c,test2:%c\n", i, *pp, *p, *test, *test2);

            *s1++ = *(ascii[i]);
            if (i == 54)
            {
                *s1++ = *(ascii[i] + 1);
                *s1++ = *(ascii[i] + 2);
            }
            break;
        }
    }
    pp = p + 1;
    *s1++ = '\0';
    return s;
}

int main()
{
    const char *x = ".... . -.--   .--- ..- -.. .";
    char *y = decode_morse("...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- -.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... .   .-.. .- --.. -.--   -.. --- --. .-.-.-  ");
    printf("%s\n", y);
}