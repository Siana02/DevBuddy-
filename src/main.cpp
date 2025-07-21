// src/main.cpp

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

// =============== ✅ Feature 1: Timestamp Formatting ===============
std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t current = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&current), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// =============== ✅ Feature 2: Log Task Start/Stop ===============
void logTask(const std::string& taskName, const std::string& action) {
    std::ofstream logFile("task_log.txt", std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "❌ Failed to open log file." << std::endl;
        return;
    }

    logFile << "[" << action << "] " << taskName << " - " << getCurrentTimestamp() << std::endl;
    logFile.close();
}

// =============== ✅ Feature 3: Suggest Commit Messages ===============
std::string generateCommitMessage(const std::string& taskName) {
    std::stringstream message;
    message << "✨ " << taskName << ": implemented core logic";
    return message.str();
}

// =============== ✅ Feature 4: Display Menu ===============
void displayMenu() {
    std::cout << "\n=== DevBuddy: Productivity Tracker ===\n";
    std::cout << "1. Start a task\n";
    std::cout << "2. End a task\n";
    std::cout << "3. Suggest commit message\n";
    std::cout << "4. Exit\n";
    std::cout << "Select an option: ";
}

// =============== ✅ Feature 5: Main App Logic ===============
int main() {
    int choice;
    std::string taskName;

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();  // Clear newline from input buffer

        switch (choice) {
            case 1:
                std::cout << "Enter task name to start: ";
                std::getline(std::cin, taskName);
                logTask(taskName, "START");
                std::cout << "✅ Started tracking: " << taskName << std::endl;
                break;

            case 2:
                std::cout << "Enter task name to stop: ";
                std::getline(std::cin, taskName);
                logTask(taskName, "END");
                std::cout << "⏹️ Stopped tracking: " << taskName << std::endl;
                break;

            case 3:
                std::cout << "Enter task name for commit suggestion: ";
                std::getline(std::cin, taskName);
                std::cout << "💡 Suggested commit message:\n";
                std::cout << generateCommitMessage(taskName) << std::endl;
                break;

            case 4:
                std::cout << "👋 Goodbye!\n";
                return 0;

            default:
                std::cout << "❌ Invalid option. Try again.\n";
        }
    }
}

