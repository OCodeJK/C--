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
    cout << "(2) Store name, phone, email in a friends struct array slot" << endl;
    cout << "(3) Write contents of the array into 'friends.dat' as binary data" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

    friends myarray[5];
    ofstream fout("friends.dat", ios::out | ios::binary);
    if (fout.good()) {

        for (int i = 0; i < 3; i++) 
        {
            //get details from input
            cout << "Name: ";
            cin >> myarray[i].name;
            cout << "Phone: ";
            cin >> myarray[i].phone;
            cout << "Email: ";
            cin >> myarray[i].email;
            
            cout << endl;

            //write the structure with user input to file
            fout.write(reinterpret_cast <const char*> (myarray), sizeof(friends) * 3);
        }
        fout.close();
    }

    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "(1) Reading contents of an entire array of friends struct from" << endl;
    cout << "    binary file 'friends.dat', and store them in local array" << endl;
    cout << "(2) Loop through the array of friends struct 'xArray' and" << endl;
    cout << "    display its content ..." << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    
    ifstream fin("friends.dat", ios::out | ios::binary);
    if (fin.good()){
        for (int i = 0; i < 3; i++){
            //read struct from the file
            fin.read(reinterpret_cast<char*> (myarray), sizeof(friends) * 3);

            //print details
            cout << "Name: " << myarray[i].name << endl;
            cout << "Phone: " << myarray[i].phone << endl;
            cout << "Email: " << myarray[i].email << endl;
            cout << endl;
        }
        fin.close();
    }
    return 0;
}