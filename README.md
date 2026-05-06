# 🪓 Hangman — C++ Console Game

A classic Hangman game written in C++ that runs in your terminal. Guess the hidden word one letter at a time before the man gets hanged!

---

## 📸 Preview

```
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========

_ r o g r a _ _ i n _

Guessed letters: r o g i n
Mistakes left: 1
Enter a letter:
```

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler supporting **C++11** or later (e.g. `g++`, `clang++`)
- `make` (optional, for Makefile build)
- `cmake` (optional, for CMake build)

### Build & Run

**Option 1 — Direct compile**
```bash
g++ -std=c++11 -o hangman hangman.cpp
./hangman
```

**Option 2 — Makefile**
```bash
make
./hangman
```

**Option 3 — CMake**
```bash
mkdir build && cd build
cmake ..
cmake --build .
./hangman
```

---

## 🎮 How to Play

1. A random word is chosen and displayed as underscores (`_ _ _ _`).
2. Enter one letter per turn to guess.
3. A correct guess reveals all matching letters in the word.
4. A wrong guess adds a body part to the gallows.
5. You have **6 wrong guesses** before the game is over.
6. Win by guessing the full word before the hangman is complete!

---

## 📁 Project Structure

```
hangman-cpp/
├── hangman.cpp       # Main game source
├── CMakeLists.txt    # CMake build config
├── Makefile          # Simple Makefile
├── .gitignore        # Git ignore rules
└── README.md         # This file
```

---

## 🛠 Features

- ASCII art gallows with 7 progressive stages
- 15 built-in words chosen at random each round
- Duplicate guess detection
- Play again prompt after each round
- Cross-platform (Linux, macOS, Windows with MinGW)

---

## 📝 License

This project is open source under the [MIT License](LICENSE).
