#include "Helpers/InputHelper.cpp"
#include "Helpers/TextColours.cpp"
#include "model/GameLogic.cpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>

class Controller {
private:
    GameLogic gameLogic;
    InputHelper inputHelper;

    std::vector<std::string> character;
    std::vector<std::string> codeMakersColorSequence;
    std::vector<std::string> resultsList;
    int numberOfGuessesAllowed;

public:
    Controller() {
        resultsList = std::vector<std::string>();
        //inputHelper = InputHelper();
        codeMakersColorSequence = std::vector<std::string>();
        codeMakersColorSequence.push_back("Red");
        codeMakersColorSequence.push_back("Green");
        codeMakersColorSequence.push_back("Yellow");
        codeMakersColorSequence.push_back("Blue");
        codeMakersColorSequence.push_back("Purple");
        codeMakersColorSequence.push_back("Maroon");
        codeMakersColorSequence.push_back("Navy");
        codeMakersColorSequence.push_back("White");
        character = std::vector<std::string>{"r", "g", "b", "y", "p", "m", "n", "w"};
        //gameLogic = gameLogic(numberOfGuessesAllowed);

    }
    void displayGameMenu() {
        std::cout << "Please select an option from the main menu below:\n"
                    "1: one human codemaker and one human codebreaker\n" 
                    "2: one computer-based codemaker and one human codebreaker\n" 
                    "0: For Exit Program\n"  << std::endl;
    }

    void runGame() {
        bool gameOver = false;
        int menuChoiceSelected = 0;
        do {
            displayGameMenu();
            std::cin >> menuChoiceSelected;
            switch (menuChoiceSelected) {
                case 1:
                    PlayerVsPlayer();
                    break;
                case 2:
                    PlayerVsComputer();
                    break;
                case 0:
                    std::exit(0);
                    break;
                default:
                    std::cout << TextColours::TEXT_RED;
                    std::cout << "Oops! Something Went Wrong" << std::endl;
                    break;
            }
        } while (!gameOver);
    }

    // Defining the starting sequence to be created by the codemaker

    void PlayerVsComputer()
    {
        std::vector<std::string> computersCodeSequence = getComputersStartingSequence();
        std::string st = gameLogic.ComputerVsHuman(getGuessUsingFirstLetterOfColour(computersCodeSequence), codeMakersColorSequence, computersCodeSequence.size());
        resultsList.push_back("Codemaker sets the code: " + st);
        std::cout << "Codemaker sets the code: " << st << std::endl;
    }

    void PlayerVsPlayer() {
        std::vector<std::string> code = humanDefineCodes();
        std::string st = gameLogic.humanVsHuman(getGuessUsingFirstLetterOfColour(code), codeMakersColorSequence, code.size());
        resultsList.push_back("Codemaker sets the code: " + st);
        std::cout << "Codemaker sets the code: " << st << std::endl;
    }

    std::vector<std::string> getComputersStartingSequence()
    {
        std::vector<std::string> computerStartingSequence;
        int sequenceLength = rand() % 6 + 3;
        for (int i = 0; i < sequenceLength; i++)
        {
            computerStartingSequence.push_back(character[rand() % 8]);
        }
        return computerStartingSequence;
    }

    std::vector<std::string> getGuessUsingFirstLetterOfColour(std::vector<std::string> playerGuess) {
        std::vector<std::string> codeBreakersColorGuesses;
        for (int i = 0; i < playerGuess.size(); i++) {
            switch (playerGuess[i][0]) {
                case 'r':
                    codeBreakersColorGuesses.push_back("Red");
                    break;
                case 'g':
                    codeBreakersColorGuesses.push_back("Green");
                    break;
                case 'b':
                    codeBreakersColorGuesses.push_back("Blue");
                    break;
                case 'y':
                    codeBreakersColorGuesses.push_back("Yellow");
                    break;
                case 'p':
                    codeBreakersColorGuesses.push_back("Purple");
                    break;
                case 'm':
                    codeBreakersColorGuesses.push_back("Maroon");
                    break;
                case 'n':
                    codeBreakersColorGuesses.push_back("Navy");
                    break;
                case 'w':
                    codeBreakersColorGuesses.push_back("White");
                    break;
                default:
                    codeBreakersColorGuesses.push_back("Nan");
                    break;
            }
        }
        return codeBreakersColorGuesses;
    }

    std::vector<std::string> humanDefineCodes() {
        std::vector<std::string> code;
        do {
            std::string st = inputHelper.readString("Enter codes with name or format like 'y m l'");
            std::string delimiter = " ";
            size_t pos = 0;
            std::string token;
            while ((pos = st.find(delimiter)) != std::string::npos) {
                token = st.substr(0, pos);
                code.push_back(token);
                st.erase(0, pos + delimiter.length());
            }
            code.push_back(st);
            if (code.size() < 3 || code.size() > 8) {
                std::cout << "code not able to specify the number (between 3-8) set code again" << std::endl;
                std::cout << "Codemaker sets the code: ";
            }
        } while (code.size() < 3 || code.size() > 8);
        return code;
    }


    void showScore(int score) {
        std::cout << "\nCodemaker score = " << score << " (" << numberOfGuessesAllowed << " guesses)" << std::endl;
    }
    void showResult(std::vector<int> scoreList) {
        std::cout << std::endl;
        for (int i = 0; i < scoreList.size(); i++) {
            std::cout << "Games: " << (i + 1) << "  Codemaker score = " << scoreList[i] << " (" << numberOfGuessesAllowed << " guesses)" << std::endl;
        }
    }
    int getnumberOfGuessesAllowed() {
        return numberOfGuessesAllowed;
    }
    std::vector<std::string> getResultsList() {
        return resultsList;
    }
    GameLogic getgameLogic() {
        return gameLogic;
    }
};

    
