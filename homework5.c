// Ex 1
#include <stdio.h>
#include <string.h>
int main() 
{
    int count;
    printf("Enter number of names: ");
    if (scanf("%d", &count) != 1 || count <= 0 || count > 50) 
    {
        printf("Error\n");
        return 1;
    }
    char list[50][50];
    for (int i = 0; i < count; ++i) 
    {
        scanf("%49s", list[i]);
    }
    printf("\nNames:\n");
    for (int i = 0; i < count; ++i) 
    {
        int dup_found = 0;
        for (int j = i + 1; j < count; ++j) 
        {
            if (strcmp(list[i], list[j]) == 0) 
            {
                dup_found = 1;
                break;
            }
        }
        if (dup_found) 
        {
            printf("%s\n", list[i]);
        }
    }
    return 0;
}
// Ex 2
#include <stdio.h>
int main() 
{
    int rows, cols;
    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0 || rows > 50 || cols > 50) 
    {
        printf("Invalid input.\n");
        return 1;
    }
    int matrix[50][50], t_matrix[50][50];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            t_matrix[j][i] = matrix[i][j];
        }
    }
    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < cols; ++i) 
    {
        for (int j = 0; j < rows; ++j)
        {
            printf("%d ", t_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
// Ex 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n = 10;
    if (argc == 2 && argv[1][0] == '-') {
        n = atoi(argv[1] + 1);
        if (n <= 0) n = 10;
    }
    char buffer[500][50];
    int total = 0;
    printf("Enter text (Ctrl+D to end input):\n");
    while (total < 500 && fgets(buffer[total], 50, stdin) != NULL) {
        total++;
    }
    int start = (total - n) > 0 ? total - n : 0;
    printf("\nLast %d lines:\n", n);
    for (int i = start; i < total; ++i) {
        printf("%s", buffer[i]);
    }
    return 0;
}
// Ex 4
#include <stdio.h>
#include <string.h>
void sort_strings(char arr[][100], int n, int (*cmp)(const char*, const char*)) 
{
    char tmp[100];
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            if (cmp(arr[i], arr[j]) > 0) 
            {
                strcpy(tmp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], tmp);
            }
        }
    }
}
int alpha_cmp(const char *a, const char *b) 
{
    return strcmp(a, b);
}
int main() 
{
    int count;
    char list[100][100];
    printf("Enter number of strings: ");
    if (scanf("%d", &count) != 1 || count <= 0 || count > 100) 
    {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter %d strings:\n", count);
    for (int i = 0; i < count; ++i) 
    {
        scanf("%49s", list[i]);
    }
    sort_strings(list, count, alpha_cmp);
    printf("\nSorted strings:\n");
    for (int i = 0; i < count; ++i) 
    {
        printf("%s\n", list[i]);
    }
    return 0;
}