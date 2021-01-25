#include <stdio.h>

size_t get_count(const char *s)
{
    int cnt = 0;
    while (*s)
    {
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u')
        {
            cnt++;
        }
        s++;
    }
    return cnt;
}
int main()
{
    char word[111];
    scanf("%s",&word);
    printf("%d\n",get_count(word));
    
}