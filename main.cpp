#include "file_funcs.cpp"

int main(){
    // Get currently displayed LB entries
    std::vector <Entry> ents = readFile();
    Entry b = readNew();
    std::vector<Entry> sorted = sortEnt(ents, b);
    writeFile(sorted);
    return 0;
}