#include <string.h>
#include "testfw.h"
#include "datapoint.h"

TEST(datapoint_new, {
    // Arrange, Act
    DP *dp = datapoint_new("name", 1234.5);

    // Assert
    ASSERT_NOT_NULL(dp);
    ASSERT_STR_EQ("name", dp->name);
    ASSERT_EQ(1234.5, dp->value);

    free(dp);
})

TEST(datapoint_append_empty, {
    // Arrange
    DP *dp_a = datapoint_new("dp_a", 0);

    // Act
    DP *result = datapoint_append((void*)0, dp_a);

    // Assert
    ASSERT_EQ(dp_a, result);
    ASSERT_EQ((void*)0, dp_a->next);

    free(dp_a);
})

TEST(datapoint_append_two_items, {
    // Arrange
    DP *dp_a = datapoint_new("dp_a", 0);
    DP *dp_b = datapoint_new("dp_b", 0);
    DP *dp_c = datapoint_new("dp_c", 0);

    // Act
    DP *result1 = datapoint_append(dp_a, dp_b);
    DP *result2 = datapoint_append(dp_a, dp_c);

    // Assert
    ASSERT_EQ(dp_a, result1);
    ASSERT_EQ(dp_a, result2)
    ASSERT_EQ(dp_b, dp_a->next);
    ASSERT_EQ(dp_c, dp_b->next);

    free(dp_a);
    free(dp_b);
    free(dp_c);
})

TEST_RUNNER(datapoint, {
    RUN_TEST(datapoint_new);
    RUN_TEST(datapoint_append_empty);
    RUN_TEST(datapoint_append_two_items);
})
