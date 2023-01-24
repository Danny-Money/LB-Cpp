#include <string>

class Entry{
    public:
        // These functions return their assigned parameter (i.e. getScore returns the entry's score, ect.)
        int getScore();
        std::string getName();
        std::string getTeam();
        std::string toString(); // Special function that returns the internal values of the entry as a string.

        // Returns true if the Entry objects contain the same data.
        bool equals(Entry in);

        // These are just the defined constructors.
        Entry(); // Defualt constructor that creates an Entry object with empty score & team # values, and the name set as 'Daniel Money'.
        Entry(std::string vals[]); // Expects an array of type std::string with 3 objects (in expected order): score, name, team number.
    private:
        // Variables stored privately to prevent access from outside code.
        int _score;
        std::string _teamNum;
        std::string _entName;
};