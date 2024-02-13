#include <iostream>
#include <string>

class InputHelper
{
private:
    std::istream &reader;

public:
    InputHelper(std::istream &input) : reader(input) {}

    char readCharacter(const std::string &prompt, const std::string &validCharacters)
    {
        char inputText;
        bool inputError;
        do
        {
            inputError = false;
            std::cout << prompt << ": ";
            reader >> inputText;
            reader.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            inputText = std::toupper(inputText);
            if (validCharacters.find(inputText) == std::string::npos)
            {
                inputError = true;
                std::cout << "Character out of range: please re-enter: ";
            }
        } while (inputError);
        return inputText;
    }

    std::string readString(const std::string &prompt)
    {
        std::cout << prompt << ": ";
        std::string inputText;
        std::getline(reader, inputText);
        return inputText;
    }

    int readInt(const std::string &prompt, int max, int min)
    {
        int inputNumber = 0;
        bool inputError;
        do
        {
            inputError = false;
            std::cout << prompt << ": ";
            if (!(reader >> inputNumber))
            {
                inputError = true;
                std::cout << "Not a valid number: please re-enter: ";
                reader.clear();
                reader.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            reader.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (inputNumber < min || inputNumber > max)
            {
                inputError = true;
                std::cout << "Number out of range: please re-enter\n";
            }
        } while (inputError);
        return inputNumber;
    }

    double readDouble(const std::string &prompt)
    {
        double inputNumber = 0.0;
        bool inputError;
        do
        {
            inputError = false;
            std::cout << prompt << ": ";
            if (!(reader >> inputNumber))
            {
                inputError = true;
                std::cout << "Not a valid number: please re-enter: ";
                reader.clear();
                reader.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            reader.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (inputError);
        return inputNumber;
    }
};
