#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include "func.h"
using namespace std;

int main(int argc, char *argv[]) {
    srand((unsigned)time(0));
    
    int x = atoi(argv[1]);
    writeFile(x);

    std::cout << "Файл создан!";
}