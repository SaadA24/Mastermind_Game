#include "Helpers/InputHelper.cpp"
#include "Model/Game.cpp"
#include <iostream>
#include <vector>
#include <random>

class GameLogic : public Game {
private:
    InputHelper inputHelper;
    int numberOfGuessesAllowed;
    int codeBreakersScore = 0;
    std::vector<int> scoreList;

public:
    GameLogic(int numberOfGuessesAllowed) {
        this -> numberOfGuessesAllowed = numberOfGuessesAllowed;
        scoreList = std::vector<int>();
    }

    std::string ComputerVsHuman(std::vector<std::string>& codeMakersStartSequence, std::vector<std::string>& orig, int length) {
        codeBreakersScore = 0;
        std::cout << "The Computer codemaker sets the code: ";

        // Hide color sequence set by computer in the form of a series of x's (xxxxxxx)

        std::string codemakersStartSequenceHidden = "";
        for (int i = 0; i < codeMakersStartSequence.size(); i++) {
            codemakersStartSequenceHidden += "X ";
        }
        codemakersStartSequenceHidden += "\n";
        std::cout << std::endl;

        // Allow codebreaker to guess the sequence one color at a time

        for (int i = 0; i < numberOfGuessesAllowed; i++) {
            codemakersStartSequenceHidden += "\nGuess " + std::to_string(i + 1) + ": ";
            std::vector<std::string> codeBreakersGuesses;

            do {
                std::string input = inputHelper.readString("Player1: Please enter a guess using only the first letter of one of the following colours:  ");
                std::istringstream iss(input);
                std::string token;
                while (std::getline(iss, token, ' ')) {
                    codeBreakersGuesses.push_back(token);
                }
            } while (codeBreakersGuesses.size() < 3 || codeBreakersGuesses.size() > 8);

            for (int k = 0; k < codeBreakersGuesses.size(); k++) {
                std::string color = getColor(orig, codeBreakersGuesses[k][0]);
                if (!color.empty()) {
                    result += color + " ";
                } else {
                    result += codeBreakersGuesses[k] + " ";
                }
            }

            if (i == numberOfGuessesAllowed - 1) {
                codeBreakersScore += 2;
            } 
            result += "\nResponse: " + playGuess(codeMakersStartSequence, codeBreakersGuesses, length);
            std::cout << "\nCodemaker score = " << codeBreakersScore << " (" << (i + 1) << " guesses)";
            result += "\nCodemaker score = " + std::to_string(codeBreakersScore) + " (" + std::to_string(i + 1) + " guesses)";
        }

        scoreList.push_back(codeBreakersScore);

        return result;
    }

    std::string humanVsHuman(std::vector<std::string> &codeMakersStartSequence, std::vector<std::string> &orig, int length) override
    {
        std::cout << "Player 1: Codemaker! Please set the code: ";
        score = 0;
        std::string result = "";
        for (int i = 0; i < codeMakersStartSequence.size(); i++)
        {
            result += codeMakersStartSequence[i] + " ";
            std::cout << codeMakersStartSequence[i] + " ";
        }
        result += "\n";
        std::cout << std::endl;
        for (int i = 0; i < numberOfGuessesAllowed; i++)
        {
            result += "\nGues " + std::to_string(i + 1) + ": ";
            std::vector<std::string> Gues;

            do {
                std::string input = inputHelper.readString("Enter Gues with name or format like 'y m l' ");
                std::istringstream iss(input);
                std::string token;
                while (std::getline(iss, token, ' ')) {
                    Gues.push_back(token);
                }

                if (Gues.size() < 3 || Gues.size() > 8) {
                    std::cout << "Gues not able to specify the number (between 3-8)  set guess again";
                    std::cout << "\nGues " << (i + 1) << ": ";
                }
            } while (Gues.size() < 3 || Gues.size() > 8);

            for (int k = 0; k < Gues.size(); k++) {
                std::string color = getColor(orig, Gues[k][0]);
                if (!color.empty()) {
                    result += color + " ";
                } else {
                    result += Gues[k] + " ";
                }
            }

            if (i == numberOfGuessesAllowed - 1) {
                score += 2;
            } else {
                score++;
            }

            result += "\nResponse: " + playGuess(codeMakersStartSequence, Gues, length);
            std::cout << "\nCodemaker score = " << score << " (" << (i + 1) << " guesses)";
            result += "\nCodemaker score = " + std::to_string(score) + " (" + std::to_string(i + 1) + " guesses)";
        }

        scoreList.push_back(score);

        return result;
    }

    std::vector<int> getScoreList() {
        return scoreList;
    }


    std::string getColor(std::vector<std::string>& cl, char ch) {
        for (int i = 0; i < cl.size(); i++) {
            if (std::tolower(cl[i][0]) == std::tolower(ch)) {
                return cl[i];
            }
        }
        return "";
    }

    std::string playGuess(std::vector<std::string>& codeMakersStartSequence, std::vector<std::string>& codeBreakersGuess, int length) {
        std::string guessString = "";

        if (codeBreakersGuess.size() <= length) {
            length = codeBreakersGuess.size();
        }

        for (int j = 0; j < codeBreakersGuess.size(); j++) {
            if (j < length) {
                if (std::tolower(codeBreakersGuess[j][0]) == std::tolower(codeMakersStartSequence[j][0])) {
                    guessString += "Black ";
                } else if (!getColor(codeMakersStartSequence, std::tolower(codeBreakersGuess[j][0])).empty()) {
                    guessString += "White ";
                }
            } else {
                if (!getColor(codeMakersStartSequence, std::tolower(codeBreakersGuess[j][0])).empty()) {
                    guessString += "White ";
                }
            }
        }

        return guessString;
    }
};
