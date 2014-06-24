#include <string.h>
#include <assert.h>
#include "datapoint.h"

#define STR(x) #x
#define TEST(name, body) \
    int test_##name() { \
        int success = 1; \
        do body while (0); \
        printf("[%s] %s\n", success ? " OK " : "FAIL", STR(name)); \
        return 1 - success; \
    }

#define ASSERT(expr) { \
        if (!(expr)) { success = 0; }\
    }

#define TEST_RUNNER(name, body) \
    int test_##name() { \
        int failures = 0; \
        do body while (0); \
        return failures; \
    }
#define RUN_TEST(name) \
    failures += test_##name();

TEST(datapoint_new, {
    DP* dp = datapoint_new("name", 1234.5);

    ASSERT(dp != nil);
    ASSERT(strcmp(dp->name, "name") == 0);
    ASSERT(dp->value == 1234.5);

    free(dp);
})

TEST_RUNNER(datapoint, {
    RUN_TEST(datapoint_new);
})
