add_executable(runTests
    test_main.cpp
    tests_tasks_manager.cpp
)
target_link_libraries(runTests
    gtest
    gtest_main
    pthread
  # Replace with your actual target if needed
)

