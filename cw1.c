// Ex 1
#include <stdio.h>
void to_str(int n, char str[]) 
{
    int temp = n, i = 0, negative = 0;
    if (n < 0) 
    {
        negative = 1;
        temp = -temp;
    }
    int num_digits = 0;
    int k = temp;
    do 
    {
        k /= 10;
        num_digits++;
    } while (k != 0);
    int len = num_digits + negative;
    str[len] = '\0';
    i = len - 1;
    while (num_digits--) 
    {
        str[i--] = (temp % 10) + '0';
        temp /= 10;
    }
    if (negative)
    {
        str[0] = '-';
    }
}
int main() 
{
    int num;
    char s[50];
    printf("Input: ");
    if (scanf("%d", &num) != 1) 
    {
        printf("Error\n");
        return 1;
    }
    to_str(num, s);
    printf("String: %s\n", s);
    return 0;
}
// Ex 2
#include <stdio.h>
int main() 
{
    int choice;
    float num1, num2, res;
    while (1) 
    {
        printf("1. Add\n2. Sub\n3. Mult\n4. Div\n5. Quit\n");
        printf("Choose: ");
        if (scanf("%d", &choice) != 1) 
        {
            printf("Error\n");
            return 1;
        }
        if (choice == 5) 
        {
            printf("...\n");
            break;
        }
        if (choice < 1 || choice > 5) 
        {
            printf("Error\n");
            continue;
        }
        printf("Input first: ");
        if (scanf("%f", &num1) != 1) 
        {
            printf("Error\n");
            return 1;
        }
        printf("Input second: ");
        if (scanf("%f", &num2) != 1) 
        {
            printf("Error\n");
            return 1;
        }
        switch (choice) 
        {
            case 1:
                res = num1 + num2;
                printf("Result: %.3f\n", res);
                break;
            case 2:
                res = num1 - num2;
                printf("Result: %.3f\n", res);
                break;
            case 3:
                res = num1 * num2;
                printf("Result: %.3f\n", res);
                break;
            case 4:
                if (num2 == 0) 
                {
                    printf("Error\n");
                } 
                else 
                {
                    res = num1 / num2;
                    printf("Result: %.3f\n", res);
                }
                break;
        }
    }
    return 0;
}
// Ex 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() 
{
    int guess, target;
    srand((unsigned int)time(NULL));
    target = rand() % 100 + 1;
    printf("Guess 1-100: ");
    while (1) 
    {
        if (scanf("%d", &guess) != 1) 
        {
            printf("Error\n");
            return 1;
        }
        if (guess < target) 
        {
            printf("Low try again: ");
        } 
        else if (guess > target) 
        {
            printf("High try again: ");
        } 
        else 
        {
            printf("You are right\n");
            break;
        }
    }
    return 0;
}