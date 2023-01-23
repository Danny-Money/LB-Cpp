#include <fstream>
#include "lbEntry.cpp"
#include <vector>

std::vector <Entry> readFile() {
    std::vector <Entry> vec;
    std::ifstream filein ("testfile.txt");
    if (filein.is_open()) {
        std::string input;
        while(filein.good()) {
            std::getline(filein, input);
            std::string temp[3];
            int a = 0;
            for (int i = 0; i < input.length(); i++){
                if(input.substr(i,1) != ",") {
                    std::string temp_str = temp[a] + input.substr(i,1);
                    temp[a] = temp_str;
                } else {
                    a++;
                }
            }
            vec.push_back(Entry(temp));
        }
    }
    return vec;
}