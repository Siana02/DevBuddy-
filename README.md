# DevBuddy++
A modern C++ command-line productivity assistant for developers. Automates project setup, Dockerizes C++ apps, tracks task time, suggests commit messages, and integrates with GitHub. Built with modular C++, unit tests, and CMake.

Streamline your workflow with devbuddy++.

DevBuddy++ automates common tasks like initializing Git repositories, generating `README.md` and `.gitignore`, Dockerizing basic C++ apps, tracking time spent on tasks, and even offering smart commit message suggestions. It supports syncing with GitHub using a personal access token (PAT) and includes unit tests for key components.

---

## 🚀 Features

- 📁 Initialize a Git repository
- 📄 Generate a `README.md` template and a `.gitignore` file
- 🐳 Dockerize simple C++ projects
- ⏱️ Track time spent on tasks (with logs)
- 💬 Suggest conventional commit messages
- 🔗 Sync with a GitHub repo (via token)
- ✅ Built-in unit testing (using Catch2)
- ⚙️ Modular design with CMake

---

## 📸 Demo

```bash
$ ./devbuddy
Welcome to DevBuddy++
1. Initialize Git project
2. Generate README & .gitignore
3. Dockerize C++ project
4. Track task time
5. Commit message suggestion
6. Push to GitHub
7. Run tests
0. Exit


---

🛠️ Installation

Prerequisites

C++17 or newer

Git

Docker (optional)

CMake

Catch2 (for testing)


Build

git clone https://github.com/your-username/DevBuddyPlusPlus.git
cd DevBuddyPlusPlus
mkdir build && cd build
cmake ..
make
./devbuddy


---

🧪 Running Tests

cd build
ctest


---

📦 Features Breakdown

1. Git Project Initialization

Initializes a new Git repository

Generates a standard .gitignore file


2. README.md + Metadata

Auto-creates a customizable README.md template

Prompts user for project name, description, author


3. Docker Support

Generates a simple Dockerfile

Supports g++ build in container


4. Task Timer

Start and stop timers for tasks

Logs are saved to task_log.txt


5. Commit Message Suggestions

Prompts user for type of change

Suggests format like feat: add timer function


6. GitHub Integration (optional)

Uses GitHub token stored securely

Pushes local repo to remote GitHub repository



---

🧠 Technologies Used

C++17

Git & GitHub CLI

Docker

CMake

Catch2 (Unit Testing)

std::filesystem, fstream, chrono



---

📁 Folder Structure

DevBuddyPlusPlus/
├── src/
│   └── main.cpp
├── include/
│   └── devbuddy.hpp
├── tests/
│   └── test_main.cpp
├── Dockerfile
├── .gitignore
├── README.md
├── CMakeLists.txt
└── task_log.txt


---

✨ Future Improvements

CLI argument parsing with cxxopts or CLI11

GitHub API integration via libcurl or REST

Persistent config storage (e.g., .devbuddyrc)

Multi-language support



---

🤝 Contributing

Contributions, issues, and feature requests are welcome!


---

📄 License

MIT License


---

👩🏽‍💻 Author

Siana Onyango
GitHub: @siana02
Made with ❤️ and C++
