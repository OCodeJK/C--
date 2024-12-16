#include <iostream>
#include <fstream> // For file I/O
#include <cstdlib> 
#include <ctime>
#include <windows.h> //sleep for windows

using namespace std;

int main() {

    int upperLimit = 3;
    int lowerLimit = -3;
    int N = 10;

    // Create an output file stream object
    ofstream outFile("file.txt");

    // Check if the file is successfully opened
    if (!outFile) {
        cerr << "Error: Could not open the file for writing!" << endl;
        return 1;
    }

    // Write random number to the file
    for (int i = 0; i <= N; i++){
        if (upperLimit == lowerLimit) {
            return lowerLimit;
        }
        int range = abs(upperLimit - lowerLimit) + 1;
        int lowerValue = (upperLimit > lowerLimit) ? lowerLimit : upperLimit;

        Sleep(1000);
        srand(time(NULL));
        int randInt = rand() % range + lowerValue;

        outFile << "Random #" << i << " : " << randInt << endl;

    }


    // Close the file
    outFile.close();

    cout << "Data successfully written to file.txt" << endl;

    return 0;
}