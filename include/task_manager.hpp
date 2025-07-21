#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include <string>
#include <chrono>
#include <fstream>
#include <map>

/**
 * @brief Class to handle task timing and logging functionality.
 */
class TaskManager {
public:
    TaskManager(const std::string& logFilePath = "task_log.txt");

    // Start timing a new task
    void startTask(const std::string& taskName);

    // Stop timing the current task and log the time
    void stopTask();

    // Get the duration of the last task in seconds
    long getLastDuration() const;

    // Get the name of the currently active task (if any)
    std::string getCurrentTask() const;

private:
    std::string currentTask;
    std::chrono::steady_clock::time_point startTime;
    std::ofstream logFile;
    std::string logFilePath;

    void logTask(const std::string& taskName, long durationInSeconds);
};

#endif // TASK_MANAGER_HPP
