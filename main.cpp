#include "file_funcs.cpp"

int main(){
    // Get currently displayed LB entries
    std::vector <Entry> ents = readFile();
    Entry b = readNew();
    writeFile(ents, b);
    return 0;
}