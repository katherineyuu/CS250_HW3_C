#include <stdio.h>
#include <stdlib.h>

void calcTribonacci(int n)
{
    int tribonacci[n];

    tribonacci[0] = 0;
    tribonacci[1] = 1;
    tribonacci[2] = 1;

    if (n >= 3)
    {
        for (int i = 3; i <= n; i++)
        {
            tribonacci[i] = tribonacci[i - 1] + tribonacci[i - 2] + tribonacci[i-3];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", tribonacci[i]);
    }
}

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    calcTribonacci(num);

    return EXIT_SUCCESS;
}