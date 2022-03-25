// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Vignere Cipher.cpp
// Program Description: This program ciphers and deciphers message usuig a key that the user entre
// Last Modification Date: 24/2/2022
// Author1 and ID and Group: Rana Essam 20210133 (S1)

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        cout << "\tThis program Ciphers and Deciphers messages using a key which the user chooses using Vignere method \n\n";
        int y;
        cout << "Please, entre the number of opration: \n1.Cipher\n2.Decipher\n3.exit\n-->";
        cin >> y;
        cin.get(); //to read \n and make the user able to get the next input

        if (y == 1) {
            //cipher
            string mes_, key;
            cout << "\nplease, entre your message : ";

            getline(cin, mes_);

            while (true) { //to make sure that the user entre the right input
                if (mes_.size() > 80) {
                    cout << "invald input! \a" << endl;
                    cout << "please, entre your message again : ";
                    getline(cin, mes_);
                }
                else {
                    break;
                }
            }

            cout << "\nPlease, entre the key: ";
            getline(cin, key);

            while (true) { //to make sure that the user entre the right input
                if (key.size() > 8) {
                    cout << "invald input! \a" << endl;
                    cout << "Please, entre the key again : ";
                    getline(cin, key);

                }
                else {
                    break;
                }
            }
            transform(mes_.begin(), mes_.end(), mes_.begin(), ::toupper);
            transform(key.begin(), key.end(), key.begin(), ::toupper);
            int lenKey = key.size();
            int j = 0;
            int lenMessage = mes_.size();
            bool r = true;
            while (r) {

                for (int i = 0; i < lenKey; i++) {
                    //this case checks if all the characters in the string ciphered or not
                    if (lenMessage == 0) {
                        r = false;
                        break;
                    }
                        //to make sure that the white spaces and the numbers will not change
                    else if (mes_[j] != ' ' && isdigit(mes_[j]) == 0)
                    {
                        mes_[j] = char(((mes_[j] + key[i]) % 26) + 65);
                    }
                    lenMessage--;
                    j++; //to get the next characher in the message and make the operation on it

                }

            }
            cout << "\nCiphered message: " << mes_;
        }

        else if (y == 2) {
            //decipher
            string mes_, key, x;
            cout << "please entre your message : ";
            getline(cin, mes_);
            transform(mes_.begin(), mes_.end(), mes_.begin(), ::toupper);
            transform(key.begin(), key.end(), key.begin(), ::toupper);
            while (true) { //to make sure that the message less than or equal 80 charater
                if (mes_.size() >= 80) {
                    cout << "invald input! " << endl;
                    cout << "please entre your message again : ";
                    getline(cin, mes_);
                }
                else {
                    break;
                }
            }

            cout << "Please, entre the key: ";
            getline(cin, key);

            while (true) {
                if (key.size() > 8) {
                    cout << "invald input! " << endl;
                    cout << "Please, entre the key again : ";
                    getline(cin, key);

                }
                else {
                    break;
                }
            }

            int lenkey = key.size();
            int j = 0;
            int lenMessage = mes_.size();


            bool r = true;
            while (r) {
                for (int i = 0; i < lenkey; i++) { //TO REPEAT THE KEY TIMES EQUAL TO THE LENGHT OF THE MESSAGE
                    if (lenMessage == 0) {
                        r = false;
                        break;
                    }

                    else if (mes_[j] != ' ' && isdigit(mes_[j]) == 0)
                    {
                        mes_[j] = char(((mes_[j] - key[i] + 26) % 26) + 65);
                    }

                    lenMessage--;
                    j++; //TO MAKE THE INDEX OF THE MESSAGE COPE THE THE INDEX OF THE KEY
                }

            }
            cout << "The message : " << mes_;
        }
        else {
            break;
        }
        //to repeat some operation
        cout << "\n\n\nplease, choose:\n1.exit\n2.some operation\n-->";
        int choose;
        cin >> choose;
        if (choose == 1) {
            break;
        }
    }
    return 0;
}