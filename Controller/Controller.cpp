#include "Helpers/InputHelper.cpp"
#include "Helpers/TextColours.cpp"
#include "model/GameLogic.cpp"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>

class Controller  : GameLogic {
private:
    GameLogic gameLogic;
    InputHelper inputHelper;

    std::vector<std::string> codeMakersColorSequence;

public:
    void displayGameMenu() {
        std::cout << "Please select an option from the main menu below:\n"
                    "1: One Computer Codemaker and One Player codebreaker\n" 
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
                    PlayerVsComputer(getComputerCodemakerStartingSequence(), );
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

}
