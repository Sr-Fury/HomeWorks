// Ex 7
#include <stdio.h>
int main() 
{
    int count;
    printf("Input: ");
    if (scanf("%d", &count) != 1 || count <= 0 || count > 50) 
    {
        printf("Error\n");
        return 1;
    }
    int storage[50];
    int *p = storage;
    for (int idx = 0; idx < count; ++idx) 
    {
        printf(" el - %d : ", idx);
        if (scanf("%d", p + idx) != 1) 
        {
            printf("Error\n");
            return 1;
        }
    }
    printf(" : \n");
    for (int idx = 0; idx < count; ++idx) 
    {
        printf(" el - %d : %d \n", idx, *(p + idx));
    }
    return 0;
}
// Ex 8
#include <stdio.h>
#include <string.h>
void swap_chars(char *x, char *y) 
{
    char tmp = *x;
    *x = *y;
    *y = tmp;
}
void permute(char *str, int start, int end) 
{
    if (start == end) 
    {
        printf("%s  ", str);
    } 
    else 
    {
        for (int i = start; i <= end; ++i) 
        {
            swap_chars(&str[start], &str[i]);
            permute(str, start + 1, end);
            swap_chars(&str[start], &str[i]);
        }
    }
}
int main() 
{
    char word[50];
    printf("Input: ");
    if (scanf("%49s", word) != 1) return 0;
    int length = (int)strlen(word);
    printf("\nPermutations:\n");
    permute(word, 0, length - 1);
    printf("\n\n");
    return 0;
}
// Ex 14
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int cnt;
    printf("Ptr sort:\n\n");
    printf("n: ");
    if (scanf("%d", &cnt) != 1 || cnt <= 0) 
    {
        printf("Error\n");
        return 1;
    }
    int buf[cnt];
    int *ptr = buf;
    int i, j, tmp;
    printf("values:\n");
    for (i = 0; i < cnt; ++i) 
    {
        printf("%d: ", i + 1);
        if (scanf("%d", ptr + i) != 1) 
        {
            printf("Invalid input.\n");
            return 1;
        }
    }
    for (i = 0; i < cnt; ++i) 
    {
        for (j = i + 1; j < cnt; ++j) 
        {
            if (*(ptr + i) > *(ptr + j)) 
            {
                tmp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = tmp;
            }
        }
    }
    printf("\nsorted:\n");
    for (i = 0; i < cnt; ++i) 
    {
        printf("%d: %d\n", i + 1, *(ptr + i));
    }
    return 0;
}
// Ex 21
#include <stdio.h>
int main() 
{
    char letters[26];
    char *q = letters;
    int idx;
    for (idx = 0; idx < 26; ++idx)
    {
        *(q++) = 'A' + idx;
    }
    q = letters;
    for (idx = 0; idx < 26; ++idx) 
    {
        printf("%c ", *(q++));
    }
    putchar('\n');
    return 0;
}
// Ex 22
#include <stdio.h>
#include <string.h>
int main() 
{
    char inbuf[200], outbuf[200];
    char *r = inbuf, *w = outbuf;
    int len;
    printf("Input: ");
    if (!fgets(inbuf, sizeof(inbuf), stdin)) 
    {
        return 0;
    }
    len = (int)strlen(inbuf);
    if (len > 0 && inbuf[len-1] == '\n') 
    {
        inbuf[--len] = '\0';
    }
    r = inbuf + len;
    while (r > inbuf) 
    {
        --r;
        *w++ = *r;
    }
    *w = '\0';
    printf("Reversed: %s\n", outbuf);
    return 0;
}