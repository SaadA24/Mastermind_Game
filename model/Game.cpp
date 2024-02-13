#include <vector>
#include <string>

class Game {
public:
    virtual std::string ComputerVsHuman(std::string character[], std::vector<std::string> colorsList, std::vector<std::string> orig, int length) = 0;
        
    virtual std::string HumanVsHuman(std::vector<std::string> colorsList, std::vector<std::string> orig, int length) = 0;
};
