// Ex 1
#include <stdio.h>
int main() 
{
    int n;
    unsigned long long prev = 0, curr = 1, next;
    printf("Enter: ");
    if (scanf("%d", &n) != 1 || n < 0) 
    {
        printf("Invalid input\n");
        return 1;
    }
    if (n == 0) 
    {
        printf("Fibonacci %d = 0\n", n);
        return 0;
    } else if (n == 1) 
    {
        printf("Fibonacci %d = 1\n", n);
        return 0;
    }
    for (int i = 2; i <= n; i++) 
    {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    printf("Fibonacci %d = %llu\n", n, curr);
    return 0;
}
// Ex 2
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void cleanString(const char src[], char dst[]) 
{
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) 
    {
        if (isalnum(src[i])) 
        {
            dst[j++] = tolower(src[i]);
        }
    }
    dst[j] = '\0';
}
int isPalindrome(const char str[]) 
{
    int left = 0, right = strlen(str) - 1;
    while (left < right) 
    {
        if (str[left] != str[right]) 
        {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}
int main() 
{
    char input[100], cleaned[100];
    printf("Enter text: ");
    if (!fgets(input, sizeof(input), stdin)) 
    {
        printf("Input error.\n");
        return 1;
    }
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') 
    {
        input[len - 1] = '\0';
    }
    cleanString(input, cleaned);
    if (isPalindrome(cleaned)) 
    {
        printf("'%s' is a palindrome.\n", input);
    } 
    else 
    {
        printf("'%s' is not a palindrome.\n", input);
    }
    return 0;
}
// Ex 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
double stack[200];
int top = 0;
void push(double val) 
{ 
    stack[top++] = val; 
}
double pop() 
{ 
    return stack[--top]; 
}
int main() 
{
    char line[1000];
    printf("Postfix Calculator (+ - * / %%).\n");
    printf("Enter expressions in postfix notation (Ctrl+D to exit).\n");
    while (printf("> "), fgets(line, sizeof(line), stdin) != NULL) 
    {
        char *token = strtok(line, " \t\n");
        top = 0;
        while (token != NULL) 
        {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
            {
                push(atof(token));
            } 
            else 
            {
                if (top < 2) 
                {
                    printf("Error: insufficient operands for '%s'\n", token);
                    break;
                }
                double b = pop();
                double a = pop();
                switch (token[0]) 
                {
                    case '+': push(a + b); break;
                    case '-': push(a - b); break;
                    case '*': push(a * b); break;
                    case '/':
                        if (b != 0) 
                        {
                            push(a / b);
                        }
                        else 
                        { 
                            printf("Error: division by zero\n"); 
                            top = 0; 
                            break; 
                        }
                        break;
                    case '%':
                        if ((int)b != 0) 
                        {
                            push((int)a % (int)b);
                        }
                        else 
                        { 
                            printf("Error: modulo by zero\n"); top = 0; break; 
                        }
                        break;
                    default:
                        printf("Error: unknown operator '%s'\n", token);
                        top = 0;
                        break;
                }
            }
            token = strtok(NULL, " \t\n");
        }
        if (top == 1) 
        {
            printf("Result: %.2f\n", pop());
        } 
        else if (top > 1) 
        {
            printf("Error: too many operands left on stack\n");
        }
    }
    printf("\nExiting calculator.\n");
    return 0;
}