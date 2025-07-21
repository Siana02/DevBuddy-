#include "../include/task_manager.hpp"
#include <cassert>
#include <iostream>
#include <thread>  // For sleep simulation

void testStartAndStopTask() {
    TaskManager tm("test_log.txt");

    // Start task
    tm.startTask("TestTask1");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    // Ensure task is running
    assert(tm.getCurrentTask() == "TestTask1");

    // Stop task
    tm.stopTask();
    
    // Ensure task is cleared
    assert(tm.getCurrentTask().empty());

    std::cout << "✔ testStartAndStopTask passed\n";
}

void testSequentialTasks() {
    TaskManager tm("test_log.txt");

    tm.startTask("TaskA");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    tm.stopTask();

    tm.startTask("TaskB");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    tm.stopTask();

    assert(tm.getCurrentTask().empty());
    std::cout << "✔ testSequentialTasks passed\n";
}

void testMultipleStartCalls() {
    TaskManager tm("test_log.txt");

    tm.startTask("FirstTask");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    tm.startTask("SecondTask");  // Should auto-stop the first

    assert(tm.getCurrentTask() == "SecondTask");

    tm.stopTask();
    std::cout << "✔ testMultipleStartCalls passed\n";
}

int dummy_main() {
    testStartAndStopTask();
    testSequentialTasks();
    testMultipleStartCalls();

    std::cout << "\nAll TaskManager tests passed ✅\n";
    return 0;
}
