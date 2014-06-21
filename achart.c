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

    return datapoint_new(name_ptr, (int)strtol(value_ptr, nil, 10));
}

int main()
{
    DP *first = nil;

    while (!feof(stdin)) {
        first = datapoint_append(first, datapoint_read(stdin));
    }

    datapoint_destroy_all(first);

    return 0;
}
