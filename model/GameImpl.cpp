#include <iostream>
#include <vector>
#include <random>
#include "Helpers/InputHelper.cpp"
#include "Model/Game.cpp"

class GameImpl : public Game {
private:
    InputHelper inputHelper;
    int numberofGuess;
    int score = 0;
    std::vector<int> scoreList;

public:
    GameImpl(int numberofGuess) {
        this->numberofGuess = numberofGuess;
        scoreList = std::vector<int>();
    }

    std::string computerVsHuman(std::vector<std::string>& character, std::vector<std::string>& colorsList, std::vector<std::string>& orig, int length) override {
        score = 0;
        std::cout << "Codemaker sets the code: ";

        std::string result = "";
        for (int i = 0; i < colorsList.size(); i++) {
            result += "X ";
            std::cout << "X ";
        }
        result += "\n";
        std::cout << std::endl;

        for (int i = 0; i < numberofGuess; i++) {
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

            if (i == numberofGuess - 1) {
                score += 2;
            } else {
                score++;
            }

            result += "\nResponse: " + playGuess(colorsList, Gues, length);
            std::cout << "\nCodemaker score = " << score << " (" << (i + 1) << " guesses)";
            result += "\nCodemaker score = " + std::to_string(score) + " (" + std::to_string(i + 1) + " guesses)";
        }

        scoreList.push_back(score);

        return result;
    }

    std::string humanVsHuman(std::vector<std::string>& colorsList, std::vector<std::string>& orig, int length) override {
        std::cout << "Codemaker sets the code: ";
        score = 0;
        std::string result = "";
        for (int i = 0; i < colorsList.size(); i++) {
            result += colorsList[i] + " ";
            std::cout << colorsList[i] + " ";
        }
        result += "\n";
        std::cout << std::endl;
        for (int i = 0; i < numberofGuess; i++) {
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

            if (i == numberofGuess - 1) {
                score += 2;
            } else {
                score++;
            }

            result += "\nResponse: " + playGuess(colorsList, Gues, length);
            std::cout << "\nCodemaker score = " << score << " (" << (i + 1) << " guesses)";
            result += "\nCodemaker score = " + std::to_string(score) + " (" + std::to_string(i + 1) + " guesses)";
        }

        scoreList.push_back(score);

        return result;
    }

    std::string computerVsComputer(std::vector<std::string>& character, std::vector<std::string>& colorsList, std::vector<std::string>& tempList, int length) override {
        score = 0;

        std::string result = "";

        for (int i = 0; i < colorsList.size(); i++) {
            result += colorsList[i] + " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < numberofGuess; i++) {
            result += "\nGues " + std::to_string(i + 1) + ": ";
            std::vector<std::string> Gues(length);

            for (int k = 0; k < length; k++) {
                Gues[k] = std::string(1, character[std::rand() % 8][0]);
            }

            for (int l = 0; l < Gues.size(); l++) {
                std::string color = getColor(tempList, Gues[std::rand() % Gues.size()][0]);
                if (!color.empty()) {
                    result += color + " ";
                }
            }

            if (i == numberofGuess - 1) {
                score += 2;
            } else {
                score++;
            }

            result += "\nResponse: " + playGuess(colorsList, Gues, length);
            std::cout << "\nCodemaker score = " << score << " (" << (i + 1) << " guesses)";
            result += "\nCodemaker score = " + std::to_string(score) + " (" + std::to_string(i + 1) + " guesses)";
        }

        scoreList.push_back(score);

        return result;
    }

    std::vector<int> getScoreList() {
        return scoreList;
    }

private:
    std::string getColor(std::vector<std::string>& cl, char ch) {
        for (int i = 0; i < cl.size(); i++) {
            if (std::tolower(cl[i][0]) == std::tolower(ch)) {
                return cl[i];
            }
        }
        return "";
    }

    std::string playGuess(std::vector<std::string>& colorsList, std::vector<std::string>& Gues, int length) {
        std::string guessString = "";

        if (Gues.size() <= length) {
            length = Gues.size();
        }

        for (int j = 0; j < Gues.size(); j++) {
            if (j < length) {
                if (std::tolower(Gues[j][0]) == std::tolower(colorsList[j][0])) {
                    guessString += "Black ";
                } else if (!getColor(colorsList, std::tolower(Gues[j][0])).empty()) {
                    guessString += "White ";
                }
            } else {
                if (!getColor(colorsList, std::tolower(Gues[j][0])).empty()) {
                    guessString += "White ";
                }
            }
        }

        return guessString;
    }
};