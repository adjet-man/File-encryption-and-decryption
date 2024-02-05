# Introduction
This is a C++ program that provides a file encryption/decryption functionality.
The program consists of three main functions: encryptFile, decryptFile, and main.
# - 
encryptFile takes two parameters: the name of the file to be encrypted and the encryption key. It opens the input file for reading, creates an output file with a .enc extension for writing, reads each character from the input file and performs XOR encryption using the key. The encrypted data is then written to the output file.
# -
decryptFile takes two parameters: the name of the file to be decrypted and the decryption key. It opens the input file for reading, creates an output file with the same name as the original input file but without the .enc extension for writing, reads each character from the input file and performs XOR decryption using the key. The decrypted data is then written to the output file.
main function displays a menu with three options - Encrypt a File, Decrypt a File, and Exit. It prompts user to enter their choice (1-3) and based on their choice it either calls encryptFile, decryptFile, or exits.
# -
The program uses bitwise XOR operator (^) for encryption/decryption which is a simple technique that can be used to obfuscate data by performing bitwise operations on it using a secret key.
Overall, this program provides basic functionality for encrypting/decrypting files using XOR encryption in C++.
