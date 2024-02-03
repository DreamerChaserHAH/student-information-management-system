//
// Created by User on 03/02/2024.
//

#define TEST(name) \
    void name##_test(); \
    void run_##name##_test() { \
        printf("Running test: %s\n", #name); \
        name##_test(); \
        printf("Test %s passed\n\n", #name); \
    } \
    void name##_test()

#define ASSERT(condition) \
    do { \
        if (!(condition)) { \
            printf("Assertion failed: %s, file: %s, line: %d\n", #condition, __FILE__, __LINE__); \
            return; \
        } } while (0)