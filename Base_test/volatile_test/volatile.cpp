#include <iostream>

using namespace std;

int main(void)
{
    const volatile int local = 10;
    // int local = 10;
    // const int local = 10;
    int *ptr = (int *)&local;

    printf("Initial value of local = %d\n", local);

    *ptr = 100;

    printf("Modified value of local = %d\n", local);

    return 0;
}