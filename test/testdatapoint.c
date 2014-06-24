#include <string.h>
#include "testfw.h"
#include "datapoint.h"

TEST(datapoint_new, {
    DP* dp = datapoint_new("name", 1234.5);

    ASSERT_NOT_NULL(dp);
    ASSERT_STR_EQ("name", dp->name);
    ASSERT_EQ(1234.5, dp->value);

    free(dp);
})

TEST_RUNNER(datapoint, {
    RUN_TEST(datapoint_new);
})
