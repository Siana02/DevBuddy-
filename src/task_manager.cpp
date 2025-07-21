#include "../include/task_manager.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

TaskManager::TaskManager(const std::string& logFilePath)
    : logFilePath(logFilePath) {
    logFile.open(logFilePath, std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Failed to open log file: " + logFilePath);
    }
}

void TaskManager::startTask(const std::string& taskName) {
    if (!currentTask.empty()) {
        std::cerr << "Warning: Stopping current task '" << currentTask << "' before starting a new one." << std::endl;
        stopTask();  // Automatically stop current task
    }

    currentTask = taskName;
    startTime = std::chrono::steady_clock::now();
    std::cout << "Started task: " << taskName << std::endl;
}

void TaskManager::stopTask() {
    if (currentTask.empty()) {
        std::cerr << "No task is currently active to stop.\n";
        return;
    }

    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();

    logTask(currentTask, duration);

    std::cout << "Stopped task: " << currentTask 
              << " (Duration: " << duration << "s)\n";

    currentTask.clear();
}

long TaskManager::getLastDuration() const {
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
}

std::string TaskManager::getCurrentTask() const {
    return currentTask;
}

void TaskManager::logTask(const std::string& taskName, long durationInSeconds) {
    // Timestamp
    std::time_t now = std::time(nullptr);
    std::tm* tmPtr = std::localtime(&now);

    logFile << "[" << std::put_time(tmPtr, "%Y-%m-%d %H:%M:%S") << "] "
            << "Task: " << taskName 
            << ", Duration: " << durationInSeconds << "s\n";

    logFile.flush();  // Ensure data is written
}
