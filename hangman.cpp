#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const std::vector<std::string> WORDS = {
    "programming", "hangman", "computer", "keyboard", "monitor",
    "algorithm", "function", "variable", "compiler", "debugger",
    "elephant", "universe", "mountain", "treasure", "lantern"
};

void drawHangman(int mistakes) {
    const std::vector<std::string> stages = {
        // 0 mistakes
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========",
        // 1
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========",
        // 2
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========",
        // 3
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========",
        // 4
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========",
        // 5
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "=========",
        // 6
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "========="
    };
    std::cout << stages[mistakes] << "\n\n";
}

void printWord(const std::string& word, const std::vector<char>& guessed) {
    for (char c : word) {
        if (std::find(guessed.begin(), guessed.end(), c) != guessed.end())
            std::cout << c << " ";
        else
            std::cout << "_ ";
    }
    std::cout << "\n";
}

void printGuessed(const std::vector<char>& guessed) {
    std::cout << "Guessed letters: ";
    for (char c : guessed) std::cout << c << " ";
    std::cout << "\n";
}

bool wordGuessed(const std::string& word, const std::vector<char>& guessed) {
    for (char c : word)
        if (std::find(guessed.begin(), guessed.end(), c) == guessed.end())
            return false;
    return true;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        std::string word = WORDS[rand() % WORDS.size()];
        std::vector<char> guessed;
        int mistakes = 0;
        const int maxMistakes = 6;

        std::cout << "\n============================\n";
        std::cout << "       HANGMAN GAME\n";
        std::cout << "============================\n";
        std::cout << "Guess the word! You have " << maxMistakes << " chances.\n\n";

        while (mistakes < maxMistakes && !wordGuessed(word, guessed)) {
            drawHangman(mistakes);
            printWord(word, guessed);
            std::cout << "\n";
            if (!guessed.empty()) printGuessed(guessed);
            std::cout << "Mistakes left: " << (maxMistakes - mistakes) << "\n";
            std::cout << "Enter a letter: ";

            char guess;
            std::cin >> guess;
            guess = tolower(guess);

            if (!isalpha(guess)) {
                std::cout << "Please enter a valid letter.\n";
                continue;
            }
            if (std::find(guessed.begin(), guessed.end(), guess) != guessed.end()) {
                std::cout << "You already guessed '" << guess << "'! Try another.\n";
                continue;
            }

            guessed.push_back(guess);

            if (word.find(guess) != std::string::npos) {
                std::cout << "Good guess!\n\n";
            } else {
                mistakes++;
                std::cout << "Wrong! '" << guess << "' is not in the word.\n\n";
            }
        }

        drawHangman(mistakes);

        if (wordGuessed(word, guessed)) {
            std::cout << "🎉 You won! The word was: " << word << "\n";
        } else {
            std::cout << "💀 Game over! The word was: " << word << "\n";
        }

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> playAgain;
    }

    std::cout << "Thanks for playing Hangman!\n";
    return 0;
}
