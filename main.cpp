#include "file_funcs.cpp"
#include "lbEntry.cpp"

int main(int argc, char *argv[]){
    // Get currently displayed LB entries
    std::vector <Entry> ents = readFile();
    Entry b = readNew();
    std::vector<Entry> sorted = sortEnt(ents, b);
    writeFile(sorted);
    for (int i = 0; i < argc; i++){
        std::cout << argv[i] << std::endl;
    }
    return 0;
}