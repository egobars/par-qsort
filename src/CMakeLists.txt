set(HEADERS
    seqsort.h
    parsort.h
    common.h
)

add_library(sorting_lib INTERFACE)

target_include_directories(sorting_lib INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(sorting_lib INTERFACE Threads::Threads)
target_link_libraries(sorting_lib INTERFACE parlay)

install(TARGETS sorting_lib DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/qsort)
