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
    ofstream fout("friends.dat", ios::out | ios::binary);
    if (fout.good()) {

        for (int i = 0; i < 3; i++) 
        {
            //get details from input
            cout << "Name: ";
            cin >> x.name;
            cout << "Phone: ";
            cin >> x.phone;
            cout << "Email: ";
            cin >> x.email;

            //write the structure with user input to file
            fout.write(reinterpret_cast <const char*>(&x), sizeof(friends));
        }
        fout.close();
    }
    return 0;
}