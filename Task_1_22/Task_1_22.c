#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int GetIncrLength(FILE* file)
{
    int x, pre;
    int count = 0;
    int maxCount = 0;
    if (fscanf(file, "%d", &pre) == 0)
        return 0;
    while (fscanf(file, "%d", &x) == 1)
    {
        if (x > pre)
            count++;
        else
        {
            maxCount = max(maxCount, count);
            count = 0;
        }
        
        pre = x;
    }
    
    return count;
}

int main(int argc, char* argv[])
{
    FILE* fInput = fopen("input.txt", "r");
    if (!fInput)
        printf("Error");
    else
        printf("%d", GetIncrLength(fInput));
    return 0;
}