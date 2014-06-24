#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nil ((void*)0)
#define DP struct DataPoint

struct DataPoint {
    char name[64];
    float value;
    DP *next;
};

DP* datapoint_new(char* name, float value);
DP* datapoint_append(DP* dp, DP* newDp);
void datapoint_destroy(DP* dp);
void datapoint_destroy_all(DP* dp);
DP* datapoint_read(FILE* file);

