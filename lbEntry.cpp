#include "lbEntry.hpp"
#include <iostream>

// Default onstructor.
Entry::Entry(){
    _score = 0;
    _entName = "Daniel Money";
    _teamNum = "3536";
}

// Overloaded constructor that accepts a std::string array. See lbEntry.hpp for more info.
Entry::Entry(std::string vals[]){
    // Checks to see if array is the correct size, otherwise set default values.
    if (vals->length() != 3) {
        std::cout << "Improper input" << std::endl;
        _score = 0;
        _entName = "Daniel Money";
        _teamNum = "3536";
        return;
    } else {
        // Assigns the array values to respective variables.
        _score = std::stoi(vals[0]);
        _entName = vals[1];
        _teamNum = vals[2];
    }
}

// The following functions return their assigned variables.

int Entry::getScore(){
    return _score;
}

std::string Entry::getName(){
    return _entName;
}

std::string Entry::getTeam(){
    return _teamNum;
}

// Returns the whole data structure of the object as a string for output to a file.
std::string Entry::toString(){
    std::string rtrnVal = std::to_string(_score) + "," + _entName + "," + _teamNum;
    return rtrnVal;
}