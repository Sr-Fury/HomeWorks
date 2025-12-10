// Ex 1
#include <stdio.h>
void double_value(int *ptr) 
{
    *ptr *= 2;
}
int main(void) {
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) 
    {
        printf("Invalid input.\n");
        return 1;
    }
    double_value(&num);
    printf("Doubled value: %d\n", num);
    return 0;
}
// Ex 2
#include <stdio.h>
void calc_sum_avg(int *ptr, int size, int *sum, float *avg) 
{
    *sum = 0;
    for (int i = 0; i < size; ++i)
    {
        *sum += *(ptr + i);
    }
    *avg = (float)(*sum) / size;
}
int main() 
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Invalid input.\n");
        return 1;
    }
    int arr[n], *p = arr;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", p + i);
    }
    int sum;
    float average;
    calc_sum_avg(p, n, &sum, &average);
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);
    return 0;
}
// Ex 3
#include <stdio.h>
void copy_array(int *src, int *dest, int size) 
{
    for (int i = 0; i < size; ++i)
    {
        *(dest + i) = *(src + i);
    }
}
int main() 
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Invalid input.\n");
        return 1;
    }
    int arrA[n], arrB[n];
    int *pA = arrA, *pB = arrB;
    printf("Enter %d elements for array A:\n", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", pA + i);
    }
    copy_array(pA, pB, n);
    printf("Array B after copying:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", *(pB + i));
    }
    printf("\n");
    return 0;
}
// Ex 4
#include <stdio.h>
#include <stdlib.h>
void push(int *stk, int *top, int val) 
{
    if (*top >= 50 - 1) {
        printf("Stack overflow!\n");
        return;
    }
    (*top)++;
    *(stk + *top) = val;
}
int pop(int *stk, int *top) 
{
    if (*top < 0) {
        printf("Stack underflow!\n");
        return -1;
    }
    int val = *(stk + *top);
    (*top)--;
    return val;
}
void display(int *stk, int top) 
{
    if (top < 0) 
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; --i)
    {
        printf("%d ", *(stk + i));
    }
    printf("\n");
}
int main() 
{
    int stack[50], top = -1, choice, val;
    do {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) 
        {
            printf("Invalid input.\n");
            break;
        }
        switch (choice) 
        {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &val) != 1) 
                {
                    printf("Invalid input.\n");
                    break;
                }
                push(stack, &top, val);
                break;
            case 2:
                val = pop(stack, &top);
                if (val != -1)
                    printf("Popped: %d\n", val);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}