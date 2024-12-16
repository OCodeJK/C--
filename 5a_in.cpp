#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //Create an input stream
    ifstream readFile("file.txt");

    if (!readFile) {
        cerr << "Error: Could not open file.txt for reading!" << endl;
        return 1;
    }

    string line;
    cout << "Contents of the file.txt:" << endl;

    while (getline(readFile, line)) {
        cout << line << endl;
    }

    readFile.close();
    return 0;
}