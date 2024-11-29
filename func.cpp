#include "func.h"

using namespace std;

void writeRandomBytes(ofstream &file, int count) {
    for (int i = 0; i < count; i++) {
        unsigned char byte = rand() % 256;
        file.write((char *)&byte, sizeof(char));
    }
}

void writeFile(int x) {

    string phrase = "I love C++";

    ofstream file("binary.bin", ios_base::binary);
    writeRandomBytes(file, x);
    
    vector<unsigned char> randomArr(10);
    for (int i = 0; i < 10; i++) {
        randomArr[i] = rand() % 256;
        file.write((char*)&randomArr[i], sizeof(char));
    }

    unsigned char off = rand() % (256 - (x+10) + 1);
    file.write((char*)&off, sizeof(char));

    writeRandomBytes(file, off-1);
    
    vector<unsigned char> checkArr(10);
    for (int i = 0; i < 10; i++) {
        checkArr[i] = randomArr[i] ^ phrase[i % phrase.size()];
        file.write((char*)&checkArr[i], sizeof(char));
    }

    if (x+20+off < 256) {
        unsigned char fileLen = rand() % (256 - (x+20+off) + 1);
        writeRandomBytes(file, fileLen);
    }
    file.close();

}
