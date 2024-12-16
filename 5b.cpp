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

    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "(1) Prompt user for name, phone, email" << endl;
    cout << "(2) Store name, phone, email in a friends struct variable" << endl;
    cout << "(3) Write contents of the struct variable into 'friends.dat as binary data'" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

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
            
            cout << endl;

            //write the structure with user input to file
            fout.write(reinterpret_cast <const char*>(&x), sizeof(friends));
        }
        fout.close();
    }

    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "(1) Reading contents from binary file 'friends.dat' struct by struct" << endl;
    cout << "(2) Store binary data into temporary friends struct variable 'x'" << endl;
    cout << "    as as binary data, before accessing and display its content ..." << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    
    ifstream fin("friends.dat", ios::out | ios::binary);
    if (fin.good()){
        for (int i = 0; i < 3; i++){
            //read struct from the file
            fin.read(reinterpret_cast<char*>(&x), sizeof(friends));

            //print details
            cout << "Name: " << x.name << endl;
            cout << "Phone: " << x.phone << endl;
            cout << "Email: " << x.email << endl;
            cout << endl;
        }
        fin.close();
    }
    return 0;
}