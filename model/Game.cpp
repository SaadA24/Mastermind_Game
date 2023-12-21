#include <vector>
#include <string>

class Game {
public:
    virtual std::string computerVsHuman(std::string character[], std::vector<std::string> colorsList, std::vector<std::string> orig, int length) = 0;
    
    virtual std::string computerVsComputer(std::string character[], std::vector<std::string> colorsList, std::vector<std::string> tempList, int length) = 0;
    
    virtual std::string humanVsHuman(std::vector<std::string> colorsList, std::vector<std::string> orig, int length) = 0;
};

