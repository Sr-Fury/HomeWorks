#include <stdio.h>
#include <string.h>
int main() {
    char line[1000];
    while(fgets(line, sizeof(line), stdin) != NULL)
    {
        int n = strlen(line);
        line[n - 1] = '\0';
        n--;
        for(int i = 0, j = n - 1; i < j; i++, j--)
        {
            char k = line[i];
            line[i] = line[j];
            line[j] = k;
        }
        if(strlen(line) > 0)
        {    
            printf("%s\n", line);
        }
    }
    // char line[1000];
    // while(fgets(line, sizeof(line), stdin) != NULL)
    // {
    //     if(strlen(line) > 80)
    //     {
    //         printf("%s", line);
    //     }
    // }
    return 0;
}