add_executable(qsort_tests
    tests.cpp
)

target_link_libraries(qsort_tests
    GTest::gtest_main
    sorting_lib
)

include(GoogleTest)
gtest_discover_tests(qsort_tests
    PROPERTIES
        ENVIRONMENT "PARLAY_NUM_THREADS=4"
)
