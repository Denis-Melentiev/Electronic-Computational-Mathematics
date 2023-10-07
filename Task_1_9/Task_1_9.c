#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int CheckSequence(FILE* file, int c1, int c2, int c3, int b)
{
    int x, xPre, xNext;
    if (fscanf(file, "%d", &xPre) != 1)
        return 0;
    if (fscanf(file, "%d", &x) != 1)
        return 0;
    if (fscanf(file, "%d", &xNext) != 1)
        return 0;

    do
    {
        if (c1 * xPre + c2 * x + c3 * xNext != b)
            return 0;
        xPre = x;
        x = xNext;
    }
    while (fscanf(file, "%d", &xNext) == 1);

    return 1;
}

int main(int argc, char* argv[])
{
    FILE* fInput = fopen("input.txt", "r");
    int c1 = 1, c2 = 1, c3 = 1, b = 6;
    if (!fInput)
        printf("Error");
    else
        printf("%s", (CheckSequence(fInput, c1, c2, c3, b) ? "YES" : "NO"));
    return 0;
}