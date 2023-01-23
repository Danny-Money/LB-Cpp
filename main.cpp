#include "file_funcs.cpp"

int main(){
    // Get currently displayed LB entries
    std::vector <Entry> ents = readFile();

    // for (int i = 0; i < ents.size(); i++){
    //     std::cout << ents[i].toString() << std::endl;
    // }

    Entry b = readNew();
    writeFile(ents, b);
    return 0;
}