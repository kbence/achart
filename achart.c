#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define nil ((void*)0)
#define DP struct DataPoint

struct DataPoint {
    char name[64];
    float value;
    DP *next;
};

DP* datapoint_new(char* name, float value)
{
    DP *dp = malloc(sizeof(DP));
    strncpy(dp->name, name, sizeof(dp->name));
    dp->value = value;
    dp->next = nil;

    return dp;
}

DP* datapoint_append(DP* dp, DP* newDp)
{
    if (dp == nil) {
        return newDp;
    } else if (dp->next == nil) {
        dp->next = newDp;
    } else {
        datapoint_append(dp->next, newDp);
    }

    return dp;
}

void datapoint_destroy(DP* dp)
{
    free(dp);
}

void datapoint_destroy_all(DP* dp)
{
    DP* next;

    if (dp == nil)
        return;

    next = dp->next;
    datapoint_destroy(dp);
    datapoint_destroy_all(next);
}

DP* datapoint_read(FILE* file)
{
    const char SEP[] = " \t\r\n";
    char line[256];
    char *name_ptr, *value_ptr;

    fgets(line, sizeof(line), file);
    value_ptr = strtok(line, SEP);
    name_ptr = strtok(nil, SEP);

    if (name_ptr == nil) {
        name_ptr = value_ptr;
        value_ptr = "0";
    }

    return datapoint_new(name_ptr, (int)strtol(value_ptr, nil, 10));
}

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
