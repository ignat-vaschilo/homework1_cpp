#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

const string phrase = "I love C++";

int main() {
    srand((unsigned)time(0));

    int x;
    cout << "Введите Х (не превышает 256): ";
    cin >> x;

    ofstream file("binary.bin", ios_base::binary);
    for (int i = 0; i < x; i++) {
        unsigned char byte = rand() % 256;
        file.write((char *)&byte, sizeof(char));
    }

    vector<unsigned char> randomArr(10);
    for (int i = 0; i < 10; i++) {
        randomArr[i] = rand() % 256;
        file.write((char*)&randomArr[i], sizeof(char));
    }

    unsigned char off = rand() % 256;
    file.write((char*)&off, sizeof(char));

    for (int i = x+11; i < x+10+off; i++) {
        unsigned char byte = rand() % 256;
        file.write((char*)&byte, sizeof(char));
    }
    
    vector<unsigned char> checkArr(10);
    for (int i = 0; i < 10; i++) {
        checkArr[i] = randomArr[i] ^ phrase[i % phrase.size()];
        file.write((char*)&checkArr[i], sizeof(char));
    }

    unsigned char fileLen = rand() % (256 - (x+20+off));
    for (int i = 0; i < fileLen; i++) {
        unsigned char byte = rand() % 256;
        file.write((char *)&byte, sizeof(char));
    }

    file.close();
    cout << "Файл создан!";
}