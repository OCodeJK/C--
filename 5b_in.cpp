#include <iostream>
#include <fstream> // For file I/O
#include <cstdlib>

using namespace std;

struct friends {
        char name[64];
        long phone;
        char email[128];
};

int main() {
    friends x;
    ifstream fin("friends.dat", ios::out | ios::binary);
    if (fin.good()){
        for (int i = 0; i < 3; i++){
            //read struct from the file
            fin.read(reinterpret_cast<char*>(&x), sizeof(friends));

            //print details
            cout << "Name: " << x.name << endl;
            cout << "Phone: " << x.phone << endl;
            cout << "Email: " << x.email << endl;
            
        }
        fin.close();
    }
}