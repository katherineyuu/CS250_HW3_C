#include <stdio.h>
#include <stdlib.h>

int calcFunction(int n)
{
    int ret;
    if (n == 0) {
        return 2;
    }
    else {
        return 3*n - 2*calcFunction(n-1) + 7;
    }
}

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    printf("%d\n", calcFunction(num));

    return EXIT_SUCCESS;
}