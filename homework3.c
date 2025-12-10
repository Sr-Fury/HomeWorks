// Ex 1
#include <stdio.h>
int prime_check(int x) 
{
    if (x < 2) return 0;
    for (int k = 2; k * k <= x; ++k)
    {
        if (x % k == 0) 
        {
            return 0;
        }
    }
    return 1;
}
void find_prime_pairs(int value) 
{
    int any = 0;
    for (int a = 2; a <= value / 2; ++a) 
    {
        int b = value - a;
        if (prime_check(a) && prime_check(b)) 
        {
            printf("%d + %d = %d\n", a, b, value);
            any = 1;
        }
    }
    if (!any) 
    {
        printf("No combination to %d.\n", value);
    }
}
int main() 
{
    int num;
    printf("Enter positive integer: ");
    if (scanf("%d", &num) != 1 || num <= 0) 
    {
        printf("Error\n");
        return 1;
    }
    printf("Sum: %d\n", num);
    find_prime_pairs(num);
    return 0;
}
// Ex 2
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    char line[256];
    int left, right;
    char oper;
    printf("Enter: \n");
    while (fgets(line, sizeof(line), stdin) != NULL) 
    {
        if (sscanf(line, " %d %c %d", &left, &oper, &right) == 3) 
        {
            switch (oper) 
            {
                case '+':
                    printf("= %d\n", left + right);
                    break;
                case '-':
                    printf("= %d\n", left - right);
                    break;
                case '*':
                    printf("= %d\n", left * right);
                    break;
                case '/':
                    if (right == 0) 
                    {
                        printf("Error\n");
                    } 
                    else 
                    {
                        printf("= %d\n", left / right);
                    }
                    break;
                case '%':
                    if (right == 0) 
                    {
                        printf("Error\n");
                    } 
                    else 
                    {
                        printf("= %d\n", left % right);
                    }
                    break;
                default:
                    printf("Error'%c'\n", oper);
                    break;
            }
        } 
        else 
        {
            printf("Error: invalid expression\n");
        }
    }
    printf("Exiting calculator.\n");
    return 0;
}
// Ex 3
#include <stdio.h>
void build_pyramid(int rows) 
{
    int ri, st, sp;
    for (ri = 1; ri <= rows; ++ri) 
    {
        for (sp = 1; sp <= rows - ri; ++sp)
        {
            putchar(' ');
        }
        for (st = 1; st <= ri; ++st) 
        {
            printf("* ");
        }
        putchar('\n');
    }
}
int main() 
{
    int n;
    printf("Input number of rows: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Invalid input.\n");
        return 1;
    }
    build_pyramid(n);
    return 0;
}