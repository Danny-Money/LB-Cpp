#include "read.cpp"

int main(){
    std::vector <Entry> k = readFile();
    for (int i = 0; i < k.size(); i++) {
        std::cout << k[i].toString() << std::endl;
    }
    return 0;
}