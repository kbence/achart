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
        if ( !(expr) ) { \
            success = 0; \
            fprintf(stderr, "[%s] Expression %s appears to be false!\n", __test_name, STR(expr)); \
        } \
    }

#define ASSERT_NULL(expr) { \
        if ( (expr) != ((void*)0) ) { \
            success = 0; \
            fprintf(stderr, "[%s] %s must be NULL!\n", __test_name, STR(expr)); \
        } \
    }

#define ASSERT_NOT_NULL(expr) { \
        if ( (expr) == ((void*)0) ) { \
            success = 0; \
            fprintf(stderr, "[%s] %s must not be NULL!\n", __test_name, STR(expr)); \
        } \
    }

#define ASSERT_EQ(expr1, expr2) { \
        if ( (expr1) != (expr2) ) { \
            success = 0; \
            fprintf(stderr, "[%s] %s must equal to %s!\n", __test_name, STR(expr2), STR(expr1)); \
        } \
    }

#define ASSERT_NEQ(expr1, expr2) { \
        if ( (expr1) == (expr2)) == 0 ) { \
            success = 0; \
            fprintf(stderr, "[%s] %s must equal to %s!\n", __test_name, STR(expr2), STR(expr1)); \
        } \
    }

#define ASSERT_STR_EQ(str1, str2) { \
        if ( strcmp((str1), (str2)) != 0 ) { \
            success = 0; \
            fprintf(stderr, "[%s] %s must equal to %s!\n", __test_name, STR(str2), STR(str1)); \
        } \
    }

#define ASSERT_STR_NEQ(str1, str2) { \
        if ( strcmp((str1), (str2)) == 0 ) { \
            success = 0; \
            fprintf(stderr, "[%s] %s must equal to %s!\n", __test_name, STR(str2), STR(str1)); \
        } \
    }

#define TEST_RUNNER(name, body) \
    int test_##name() { \
        const char* __test_name = STR(name); \
        int failures = 0; \
        do body while (0); \
        return failures; \
    }

#define RUN_TEST(name) \
    failures += test_##name();
