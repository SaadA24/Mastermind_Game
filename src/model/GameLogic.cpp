#include "Helpers/InputHelper.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <set>


    std::string PlayerVsComputer(std::vector<std::string>& codeMakersStartSequence, std::vector<std::string>& orig, int codemakerSequencelength) {

        int numberOfGuessesAllowed = 10;
        int computerCodemakerScore = 0;
        int computerCodebreakerScore = 0;

        // Set starting Sequence
        std::cout << "The Computer codemaker sets the code: ";
        std::string codeMakersStartSequence = GetComputerCodemakerStartingSequence();

        // Hide code from Player and display it
        std::string codemakersStartSequenceHidden = "";
        for (int i = 0; i < codeMakersStartSequence.size(); i++) {
            codemakersStartSequenceHidden += "X ";
        }
        std::cout << codemakersStartSequenceHidden << std::endl;

        // Prompt codebreaker to input a guess
        std::cout << "Player Codebreaker: Please guess the secret code set by the codemaker using the first letter of the following colors"
                      "seperated by a space: ";


        for(int i = 0; i < numberOfGuessesAllowed; i++)
        {
            std::vector<std::string> codebreakersGuess = recordCodeBreakersGuess();
            std::string responseToCodebreakersGuess = generateCodebreakerResponse(codeMakersStartSequence, codebreakersGuess);
            


        }



        // Generate automatic response to codebreaker 
        std::string responseToCodebreakersGuess = generateCodebreakerResponse(codeMakersStartSequence, char input);
        
        // Play Game within number of guesses

        
        // Append scores

        








    }

    // 1st - get computer code maker start code


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
        

        scoreList.push_back(codeBreakersScore);

        return result;


    std::set<std::string> GetComputerCodemakerStartingSequence()
    {
        std::set colorPegsToPlaceOnBoard {"Red", "Green", "Blue", "Yellow", "Purple", "Maroon", "Navy", "Indigo"};

        std::random_device rd;
        std::mt19937 randomGenerator(rd);
        std::shuffle(colorPegsToPlaceOnBoard.begin(), colorPegsToPlaceOnBoard.end(), randomGenerator);

        std::set<std::string> computerCodemakerStartingSequenceInWords {colorPegsToPlaceOnBoard.begin(), colorPegsToPlaceOnBoard.end()};
        
        return computerCodemakerStartingSequenceInWords;
        


        int sequenceLength = rand() % 6 + 3;
        for (int i = 0; i < sequenceLength; i++)
        {
            computerCodemakerStartingSequence.push_back(character[rand() % 8]);
        }
        return computerCodemakerStartingSequence;
    }

 //
    std::string generateCodebreakerResponse(std::string& codeMakerSequence, std::string codebreakersGuess) {
        std::string responseToCodebreakersGuess = "";
        for (int i = 0; i < codeMakerSequence.size(); i++) {
            if (codebreakersGuess[i] == codeMakerSequence[i]) {
                responseToCodebreakersGuess += "Black";
            }
            if (codeMakerSequence[i] == codeMakerSequence[i])
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

        std::string recordCodebreakerGuessSequence(std::vector<std::string> codeSequence) {
        std::string codeSequenceInput;
        for (int i = 0; i < codeSequence.size(); i++) {
            switch (codeSequence[i][0]) {
                case 'r':
                    codeBreakerSequenceGuess.push_back("Red");
                    break;
                case 'g':
                    codeBreakerSequenceGuess.push_back("Green");
                    break;
                case 'b':
                    codeBreakerSequenceGuess.push_back("Blue");
                    break;
                case 'y':
                    codeBreakerSequenceGuess.push_back("Yellow");
                    break;
                case 'p':
                    codeBreakerSequenceGuess.push_back("Purple");
                    break;
                case 'm':
                    codeBreakerSequenceGuess.push_back("Maroon");
                    break;
                case 'n':
                    codeBreakerSequenceGuess.push_back("Navy");
                    break;
                case 'i':
                    codeBreakerSequenceGuess.push_back("Indigo");
                    break;
                default:
                    codeBreakerSequenceGuess.push_back("Nan");
                    break;
            }
        }
        return codeBreakerSequenceGuess;
    }



    std::vector<std::string> recordCodeBreakersGuessSequence() {
        std::string codebreakersSequence;
        do {
            std::string codeBreakerInputString = InputHelper.readString(); // read inout

            std::string token;

            size_t firstPosition = 0;
            while ((firstPosition = codeBreakerInputString.find(" ")) != std::string::npos) {
                token = codeBreakerInputString.substr(0, firstPosition);
                code.push_back(token);
                codeBreakerInputString.erase(0, firstPosition + delimiter.length());
            }
            code.push_back(codeBreakerInputString);
            if (code.size() < 3 || code.size() > 8) {
                std::cout << "code not able to specify the number (between 3-8) set code again" << std::endl;
                std::cout << "Codemaker sets the code: ";
            }
        } while (code.size() < 3 || code.size() > 8);
        return code;
    };
