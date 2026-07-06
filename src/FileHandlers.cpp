#include <fstream>

void saveData(){
    std::ofstream file("Data/Library.txt");
}
void loadData(){
    std::ifstream file("Data/Library.txt");
}
void resetData(){
    std::ofstream file("Data/Library.txt");
}