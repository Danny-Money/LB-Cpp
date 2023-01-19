#include "lbEntry.hpp"
#include <iostream>

Entry::Entry(){
    std::cout << "Constructor is called." << std::endl;
    _score = 0;
    _entName = "Daniel Money";
    _teamNum = "3536";
}

Entry::Entry(std::string vals[]){
    if (vals->length() != 3) {
        std::cout << "Improper input" << std::endl; 
        return;
    } else {
        _score = std::stoi(vals[0]);
        _entName = vals[1];
        _teamNum = vals[2];
    }
    std::cout << "Contructor with array is called" << std::endl;
}

int Entry::getScore(){
    return _score;
}

std::string Entry::getName(){
    return _entName;
}

std::string Entry::getTeam(){
    return _teamNum;
}

std::string Entry::toString(){
    std::string rtrnVal = _entName + "," + _teamNum + "," + std::to_string(_score);
    return rtrnVal;
}