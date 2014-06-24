#include <stdio.h>
#include <string.h>

#define STR(x) #x

#define TEST(name, body) \
    int test_##name() { \
        const char *__test_name = STR(name); \
        int success = 1; \
        do body while (0); \
        printf("[%s] %s\n", success ? " OK " : "FAIL", __test_name); \
        return 1 - success; \
    }

#define ASSERT(expr) { \
        if (!(expr)) { \
            success = 0; \
            fprintf(stderr, "[%s] Expression %s appears to be false!\n", __test_name, STR(expr)); \
        } \
    }

#define ASSERT_NULL(expr) ASSERT( (expr) == ((void*)0) )
#define ASSERT_NOT_NULL(expr) ASSERT( (expr) != ((void*)0) )
#define ASSERT_EQ(expr1, expr2) ASSERT( (expr1) == (expr2) )
#define ASSERT_NEQ(expr1, expr2) ASSERT( (expr1) != (expr2) )
#define ASSERT_STR_EQ(str1, str2) ASSERT( strcmp((str1), (str2)) == 0 )

#define TEST_RUNNER(name, body) \
    int test_##name() { \
        const char* __test_name = STR(name); \
        int failures = 0; \
        do body while (0); \
        return failures; \
    }

#define RUN_TEST(name) \
    failures += test_##name();
