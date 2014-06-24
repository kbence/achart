#include <stdio.h>
#include "datapoint.h"

float get_max(DP* dp)
{
    DP *ptr = dp;
    float max;

    if (ptr == nil)
        return 0;

    max = ptr->value;
    ptr = ptr->next;

    for (; ptr; ptr = ptr->next) {
        if (ptr->value > max)
            max = ptr->value;
    }

    return max;
}

char* chrrep(char* target, char rep, int length)
{
    char* ptr;

    for (ptr = target; length > 0; length--) {
        *ptr++ = rep;
    }

    *ptr = 0;

    return target;
}

void show_chart(DP* dp)
{
    char buf[80];
    float max = get_max(dp);
    int length = 79;

    for (DP* ptr = dp; ptr; ptr = ptr->next) {
        printf("%8s | %s\n", ptr->name, chrrep(buf, '#', (int)(ptr->value*length/max)));
    }
}

int main()
{
    DP *first = nil;

    while (!feof(stdin)) {
        first = datapoint_append(first, datapoint_read(stdin));
    }

    show_chart(first);

    datapoint_destroy_all(first);

    return 0;
}
