#include <string>

class Entry{
    public:
        int getScore();
        std::string getName();
        std::string getTeam();
        std::string toString();
        Entry();
        Entry(std::string vals[]);
    private:
        int _score;
        std::string _teamNum;
        std::string _entName;
};