#include "lbEntry.cpp"

int main(){
    std::string v[] = {"783","Daniel Money","3536"};
    Entry a = Entry();
    Entry b = Entry(v);
    std::cout << a.toString() << std::endl;
    std::cout << b.toString() << std::endl;
    return 0;
}