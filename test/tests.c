#include "tests.h"

int main()
{
    int failures = 0;

    failures += test_datapoint();

    return failures == 0 ? 0 : 1;
}
