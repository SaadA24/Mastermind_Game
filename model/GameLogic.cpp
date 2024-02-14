#include "Helpers/InputHelper.cpp"
#include <iostream>
#include <vector>
#include <random>


    std::string PlayerVsComputer(std::vector<std::string>& codeMakersStartSequence, std::vector<std::string>& orig, int codemakerSequencelength) {

        // set code
        std::cout << "The Computer codemaker sets the code: ";
        std::vector<std::string> codeMakersStartSequence = GetComputerCodemakerStartingSequence();

        // Hide code from Player
        std::string codemakersStartSequenceHidden = "";
        for (int i = 0; i < codeMakersStartSequence.size(); i++) {
            codemakersStartSequenceHidden += "X ";
        }
        std::cout << codemakersStartSequenceHidden << std::endl;

        // Allow codebreaker to input a guess


        // Generate automatic response to codebreaker 
        std::string responseToCodebreakersGuess = generateCodebreakerResponse();
        
        // Play Game within number of guesses

        
        // Append scores

        








    }

    // 1st - get computer code maker start code
    std::vector<std::string> GetComputerCodemakerStartingSequence()
    {
        std::vector<std::string> computerCodemakerStartingSequence;
        int sequenceLength = rand() % 6 + 3;
        for (int i = 0; i < sequenceLength; i++)
        {
            computerCodemakerStartingSequence.push_back(character[rand() % 8]);
        }
        return computerCodemakerStartingSequence;
    }

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

        std::vector<std::string> recordCodebreakerGuessSequence(std::vector<std::string> codebreakerGuess) {
        std::vector<std::string> codeBreakerSequenceGuess;
        for (int i = 0; i < codebreakerGuess.size(); i++) {
            switch (codebreakerGuess[i][0]) {
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
                case 'w':
                    codeBreakerSequenceGuess.push_back("White");
                    break;
                default:
                    codeBreakerSequenceGuess.push_back("Nan");
                    break;
            }
        }
        return codeBreakerSequenceGuess;
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
    };
