#include <fstream>
#include <vector>
#include "lbEntry.cpp"

std::vector <Entry> readFile() {
    // Reads the currently displayed scores in from the text file, then returns a vector object containing multiple Entry objects.
    std::vector<Entry> vec (5);
    std::ifstream filein ("test_text/testfile.txt");
    if (filein.is_open()) {
        std::string input;
        int b = 0;
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
            vec.at(b) = Entry(temp);
            b++;
        }
    }
    filein.close();
    return vec;
}

Entry readNew(){
    // Read the new entry into the program and return a new Entry object with the new data.
    std::ifstream filein ("test_text/test_input.txt");
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
            filein.close();
            return Entry(temp);
        }
    }
    filein.close();
    return Entry();
}

void writeFile(std::vector <Entry> sorted_ent){
    // Discard the previous bottom entry on the LB.
    std::ofstream dump_file ("test_text/test_dump.txt", std::ios::out | std::ios::app );
    dump_file << sorted_ent[sorted_ent.size() -1].toString() << std::endl;
    dump_file.close();

    sorted_ent.resize(sorted_ent.size());

    // Write the new top scores to the LB.
    std::ofstream dis_file ("test_text/testfile.txt");
    for (int i = 0; i < sorted_ent.size() - 1; i ++){
        dis_file << sorted_ent[i].toString();
        if (i < sorted_ent.size() - 2) {
            dis_file << std::endl;
        }
    }
    dis_file.close();
}