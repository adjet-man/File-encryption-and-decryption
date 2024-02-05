#include <iostream>
#include <fstream>
#include <string>



using namespace std;

// Function to encrypt a file using a given key
void encryptFile(string filename, string key) {
    // Open the input file for reading
    ifstream fin(filename);
    if (!fin) {
        cout << "Error: Cannot open file for reading." << endl;
        return;
    }
    
    // Open the output file for writing
    ofstream fout(filename + ".enc");
    if (!fout) {
        cout << "Error: Cannot open file for writing." << endl;
        return;
    }

    int keyIndex = 0;
    char c;
    
    // Read each character from the input file and perform XOR encryption using the key
    while (fin.get(c)) {
        c ^= key[keyIndex++ % key.length()];
        fout.put(c);
    }

    fin.close();
    fout.close();
    
    cout << "Encryption complete. Encrypted file: " << filename + ".enc" << endl;
}

// Function to decrypt a file using a given key
void decryptFile(string filename, string key) {
    // Open the input file for reading
    ifstream fin(filename);
    
     if (!fin) {
        cout << "Error: Cannot open file for reading." << endl;
        return;
     }
    
     // Create a new output file with the same name as the original input file but without the .enc extension
     ofstream fout(filename.substr(0, filename.length() - 4));
     
     if (!fout) {
        cout << "Error: Cannot open file for writing." << endl;
        return;
     }

     int keyIndex = 0;
     char c;

     // Read each character from the input file and perform XOR decryption using the key
     while (fin.get(c)) {
        c ^= key[keyIndex++ % key.length()];
        fout.put(c);
     }

     fin.close();
     fout.close();
     
     cout << "Decryption complete. Decrypted file: " << filename.substr(0, filename.length() - 4) << endl;
}

int main() {
    string filename, key;
    int choice;

    do {
        // Display menu options
        cout << "File Encryption/Decryption Program" << endl;
        cout << "1. Encrypt a file" << endl;
        cout << "2. Decrypt a file" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        
        // Get user input for menu option
        cin >> choice;

        switch (choice) {
            case 1:
                // Get user input for filename and encryption key, then call encryptFile function
                cout << "Enter file name: ";
                cin >> filename;
                cout << "Enter encryption key: ";
                cin >> key;
                encryptFile(filename, key);
                break;
            case 2:
                // Get user input for filename and decryption key, then call decryptFile function
                cout << "Enter file name: ";
                cin >> filename;
                cout << "Enter decryption key: ";
                cin >> key;
                decryptFile(filename, key);
                break;
            case 3:
                // Exit the program
                cout << "Goodbye!" << endl;
                break;
            default:
                 // Display error message for invalid menu option
                 cout << "Invalid choice. Please enter 1, 2, or 3." << endl;               
         }

    } while (choice != 3);

    return 0;    
}