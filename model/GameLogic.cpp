#include "Helpers/InputHelper.cpp"
#include <iostream>
#include <vector>
#include <random>

class GameLogic {
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

    std::string PlayerVsComputer(std::vector<std::string>& codeMakersStartSequence, std::vector<std::string>& orig, int codemakerSequencelength) {
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
            std::vector<std::string> codeBreakersGuess;

            do {
                std::string codeBreakerRequest = "Player 1: Codebreaker! Please enter a guess using only the first letter of one of the following colours:";
                std::istringstream iss(codeBreakerRequest);
                std::string token;
                while (std::getline(iss, token, ' ')) {
                    codeBreakersGuess.push_back(token);
                }
            } while (codeBreakersGuess.size() < 3 || codeBreakersGuess.size() > 8);

            for (int k = 0; k < codeBreakersGuess.size(); k++) {
                std::string color = getColor(orig, codeBreakersGuess[k][0]);
                if (!color.empty()) {
                    result += color + " ";
                } else {
                    result += codeBreakersGuess[k] + " ";
                }
            }

            if (i == numberOfGuessesAllowed - 1) {
                codeBreakersScore += 1;
            }

            result += "\nResponse: " + generateCodebreakerResponse(codeMakersStartSequence, codeBreakersGuess, codemakerSequencelength);

            std::cout << "\nCodemaker score = " << codeBreakersScore << " (" << (i + 1) << " guesses)";
            
            result += "\nCodebreaker score = " + std::to_string(codeBreakersScore) + " (" + std::to_string(i + 1) + " guesses)";
        }

        scoreList.push_back(codeBreakersScore);

        return result;
    }


 //
    std::string generateCodebreakerResponse(std::vector<std::string>& codeMakerSequence, char colorLetterInput) {
        std::string responseToCodebreakersGuess = "";
        for (int i = 0; i < codeMakerSequence.size(); i++) {
            if (colorLetterInput == codeMakerSequence[i][0]) {
                responseToCodebreakersGuess += "Black";
            }
            if (codeMakerSequence[i] == "r")
            {
                responseToCodebreakersGuess += "White";
            }
            else
            {
                responseToCodebreakersGuess += "x";
            }
        }
        return responseToCodebreakersGuess;
    }

};
