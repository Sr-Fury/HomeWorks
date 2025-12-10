// Ex 3-2
#include <stdio.h>
int encode_vis(char out[], char in[])
{
    int p = 0, q = 0;
    for (p = 0; in[p] != '\0'; ++p)
    {
        char ch = in[p];
        if (ch == '\n')
        {
            out[q++] = '\\';
            out[q++] = 'n';
        } 
        else if (ch == '\t')
        {
            out[q++] = '\\';
            out[q++] = 't';
        } 
        else if (ch == '\\')
        {
            out[q++] = '\\';
            out[q++] = '\\';
        } 
        else
        {
            out[q++] = ch;
        }
    }
    out[q] = '\0';
    return q;
}
int decode_vis(char out[], char in[])
{
    int i = 0, j = 0;
    while (in[i] != '\0') 
    {
        if (in[i] == '\\') 
        {
            char nxt = in[i + 1];
            if (nxt == 'n') 
            {
                out[j++] = '\n';
                i += 2;
            } 
            else if (nxt == 't') 
            {
                out[j++] = '\t';
                i += 2;
            } 
            else if (nxt == '\\') 
            {
                out[j++] = '\\';
                i += 2;
            } 
            else if (nxt == '\0') 
            {
                out[j++] = '\\';
                i++;
            } 
            else 
            {
                out[j++] = '\\';
                out[j++] = nxt;
                i += 2;
            }
        } 
        else 
        {
            out[j++] = in[i++];
        }
    }
    out[j] = '\0';
    return j;
}
int main() 
{
    int ch;
    int idx = 0;
    char raw[150];
    printf("Enter text (Ctrl+D to end):\n");
    while ((ch = getchar()) != EOF && idx < (int)sizeof(raw) - 1) 
    {
        raw[idx++] = (char)ch;
    }
    raw[idx] = '\0';
    char visual[300];
    char restored[150];
    encode_vis(visual, raw);
    printf("Escaped: %s\n", visual);
    decode_vis(restored, visual);
    printf("Unescaped: %s\n", restored);
    return 0;
}
// Ex 3-3
#include <stdio.h>
#include <ctype.h>
void unfold(char in[], char out[]) 
{
    int a = 0, b = 0;
    char left, right;
    while (in[a] != '\0') 
    {
        if (in[a] == '-' && a > 0 && in[a + 1] != '\0') 
        {
            left = in[a - 1];
            right = in[a + 1];
            if ((isdigit(left) && isdigit(right) && left < right) || (islower(left) && islower(right) && left < right) || (isupper(left) && isupper(right) && left < right)) 
            {
                for (char k = left + 1; k <= right; k++) 
                {
                    out[b++] = k;
                    a++;
                }
            } 
            else 
            {
                out[b++] = '-';
            }
        } 
        else 
        {
            out[b++] = in[a];
        }
        a++;
    }
    out[b] = '\0';
}
int main() 
{
    char src[100], dst[500];
    printf("Enter shorthand: ");
    fgets(src, sizeof(src), stdin);
    unfold(src, dst);
    printf("Expanded: %s\n", dst);
    return 0;
}
// Ex 3-5
#include <stdio.h>
#include <string.h>
static void flip(char buf[]) 
{
    int l = 0, r = (int)strlen(buf) - 1;
    while (l < r) 
    {
        char t = buf[l];
        buf[l++] = buf[r];
        buf[r--] = t;
    }
}
void num_to_base(int value, char out[], int base) 
{
    if (base < 2 || base > 36) 
    { 
        out[0] = '\0'; return; 
    }
    unsigned int unum;
    if (value < 0) 
    {
        unum = (unsigned int)(-(long)value);
    }
    else 
    {
        unum = (unsigned int)value;
    }
    int pos = 0;
    do 
    {
        int d = unum % base;
        out[pos++] = (d < 10) ? ('0' + d) : ('A' + (d - 10));
        unum /= base;
    } while (unum > 0);
    if (value < 0 && base == 10) out[pos++] = '-';
    out[pos] = '\0';
    flip(out);
}
int main() 
{
    int n, b;
    char s[100];
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) 
    {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter base (2-36): ");
    if (scanf("%d", &b) != 1 || b < 2 || b > 36) 
    {
        printf("Invalid base.\n");
        return 1;
    }
    num_to_base(n, s, b);
    printf("Number %d in base %d is: %s\n", n, b, s);
    return 0;
}