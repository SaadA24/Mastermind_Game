#include "Helpers/InputHelper.cpp"
#include "Helpers/TextColours.cpp"
#include "model/GameImpl.cpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>


class Controller {
private:
    GameImplementation gameLogic;
    InputHelper inputHelper;

    std::vector<std::string> character;
    std::vector<std::string> colorListOrginal;
    std::vector<std::string> resultsList;
    int numberOfPlayerGuesses;
    int counter;

public:
    Controller() {
        resultsList = std::vector<std::string>();
        inputHelper = InputHelper();
        colorListOrginal = std::vector<std::string>();
        colorListOrginal.push_back("Red");
        colorListOrginal.push_back("Green");
        colorListOrginal.push_back("Yellow");
        colorListOrginal.push_back("Blue");
        colorListOrginal.push_back("Purple");
        colorListOrginal.push_back("Maroon");
        colorListOrginal.push_back("Navy");
        colorListOrginal.push_back("White");
        character = std::vector<std::string>{"r", "g", "b", "y", "p", "m", "n", "w"};
        gameImpl = GameImpl(numberOfPlayerGuesses);

    }

void displayGameMenu() {
    std::cout << "Please select an option from the main menu below:\n"
                 "1: one human codemaker and one human codebreaker\n" 
                 "2: one computer-based codemaker and one human codebreaker\n" 
                 "3: one computer-based codemaker and one computer-based codebreaker.\n"
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
                    humanVsHuman();
                    showScore(gameImpl.getScoreList()[counter]);
                    counter++;
                    std::cout << std::endl;
                    break;
                case 2:
                    computerVsHuman();
                    showScore(gameImpl.getScoreList()[counter]);
                    counter++;
                    std::cout << std::endl;
                    break;
                case 3:
                    computerVsComputer();
                    showScore(gameImpl.getScoreList()[counter]);
                    counter++;
                    std::cout << std::endl;
                    break;
                case 0:
                    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
                    std::exit(0);
                    break;
                default:
                    std::cout << TextColours::TEXT_RED;
                    std::cout << "Oops! Something Went Wrong" << std::endl;
                    break;
            }
        } while (!gameOver);
    }
    void computerVsHuman() {
        std::vector<std::string> code = getRandomCodes();
        std::string st = gameImpl.computerVsHuman(character, getColorList(code), colorListOrginal, code.size());
        resultsList.push_back("Codemaker sets the code: " + st);
        std::cout << "Codemaker sets the code: " << st << std::endl;
    }
    void computerVsComputer() {
        std::vector<std::string> randomCodes = getRandomCodes();
        std::string st = gameImpl.computerVsComputer(character, getColorList(randomCodes), colorListOrginal, randomCodes.size());
        resultsList.push_back("Codemaker sets the code: " + st);
        std::cout << "Codemaker sets the code: " << st << std::endl;
    }
    void humanVsHuman() {
        std::vector<std::string> code = humanDefineCodes();
        std::string st = gameImpl.humanVsHuman(getColorList(code), colorListOrginal, code.size());
        resultsList.push_back("Codemaker sets the code: " + st);
        std::cout << "Codemaker sets the code: " << st << std::endl;
    }
    std::vector<std::string> getColorList(std::vector<std::string> code) {
        std::vector<std::string> colorsList;
        for (int i = 0; i < code.size(); i++) {
            switch (code[i][0]) {
                case 'r':
                    colorsList.push_back("Red");
                    break;
                case 'g':
                    colorsList.push_back("Green");
                    break;
                case 'b':
                    colorsList.push_back("Blue");
                    break;
                case 'y':
                    colorsList.push_back("Yellow");
                    break;
                case 'p':
                    colorsList.push_back("Purple");
                    break;
                case 'm':
                    colorsList.push_back("Maroon");
                    break;
                case 'n':
                    colorsList.push_back("Navy");
                    break;
                case 'w':
                    colorsList.push_back("White");
                    break;
                default:
                    colorsList.push_back("Nan");
                    break;
            }
        }
        return colorsList;
    }

    void showScore(int score) {
        std::cout << "\nCodemaker score = " << score << " (" << numberOfPlayerGuesses << " guesses)" << std::endl;
    }
    void showResult(std::vector<int> scoreList) {
        std::cout << std::endl;
        for (int i = 0; i < scoreList.size(); i++) {
            std::cout << "Games: " << (i + 1) << "  Codemaker score = " << scoreList[i] << " (" << numberOfPlayerGuesses << " guesses)" << std::endl;
        }
    }
    int getnumberOfPlayerGuesses() {
        return numberOfPlayerGuesses;
    }
    std::vector<std::string> getResultsList() {
        return resultsList;
    }
    GameImpl getGameImpl() {
        return gameImpl;
    }
};

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
    std::vector<std::string> getRandomCodes() {
        std::vector<std::string> code;
        int codeLength = rand() % 6 + 3;
        for (int i = 0; i < codeLength; i++) {
            code.push_back(character[rand() % 8]);
        }
        return code;
    }
