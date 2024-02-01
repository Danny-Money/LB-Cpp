#pragma once
#include "lbEntry.hpp"
#include <iostream>

// Default constructor.
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

// Checks if array is sorted & returns true/false based on result.
bool isSorted(std::vector<Entry> arr){
    bool inOrder = true;
    for (int i = 0; i < arr.size() - 1; i++){
        if (arr[i].getScore() < arr[i+1].getScore()){
            inOrder = false;
        }
    }

    return inOrder;
}

// Sorts the array based on score, and returns the sorted array.
std::vector<Entry> sortEntryArray(std::vector<Entry> arr){
    bool isSorted = false;

    while (!isSorted){
        isSorted = true;
        for (int i = 0; i < arr.size() - 1; i++){
            if (arr[i].getScore() < arr[i+1].getScore()){
                isSorted = false;
                Entry temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    return arr;
}

// Sorts a new entry into the array of entries.
std::vector<Entry> sortEnt(std::vector<Entry> arr, Entry newEnt){
    // Sorts array before adding newEnt.
    if (!isSorted(arr)){
        std::cout << "The entry array isn't sorted - sorting now." << std::endl;
        arr = sortEntryArray(arr);
    } else { std::cout << "The entry array is sorted." << std::endl; }

    // Checks the size of the entry array and resizes it if necessary.
    if (arr.size() != 5){
        std::cout << "The input vector was not the correct size." << std::endl;
        arr.resize(6);
        arr.at(5) = newEnt;
    }

    for(int i = 0; i < arr.size(); i++){
        if (newEnt.equals(arr[i])){
            std::cout << "Entry " + newEnt.toString() + " equals Entry " + arr[i].toString() << std::endl;
            arr.insert(arr.begin() + arr.size(), newEnt);
            return arr;
        }
    }

    int place = arr.size();
    for (int i = arr.size(); i >= 0; i--){
        if (newEnt.getScore() > arr[i].getScore()){
            place = i;
        }
    }
    arr.insert(arr.begin() + place, newEnt);
    return arr;
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

bool Entry::equals(Entry in){
    if (this->_teamNum == in.getTeam() && this->_entName == in.getName()){
        if (this->_score > in.getScore()){
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}