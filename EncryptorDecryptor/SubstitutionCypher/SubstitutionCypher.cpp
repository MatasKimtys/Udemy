// SubstitutionCypher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string Message_Encryptor(string message_to_encrypt, int move_ascii);
string Message_Decryptor(string message_to_decrypt, int move_ascii);

int main()
{
    //std::cout << "Put in a message to encrypt and send: ";
    string m_to_encrypt {"abcabacbacbacbbacbabcabBBBBACACBACBACBACbaCBAcbACBVAaXCAXCAXbAXCABXCB"};
    //cin >> m_to_encrypt;
    string e_message = Message_Encryptor(m_to_encrypt, 1);
    cout << e_message.length() << endl;
    cout << e_message << endl;
    cout << "\n" << endl;

    string m_to_decrypt = Message_Decryptor(e_message , 1);
    cout << m_to_decrypt << endl;

}

string Message_Encryptor(string message_to_encrypt, int move_ascii) {
    string m_to_encrypt = message_to_encrypt;
    cout << m_to_encrypt.length() << endl;
    string e_message;
    for (int i{ 0 }; i < m_to_encrypt.length(); ++i) {
        if (isupper(m_to_encrypt.at(i))) {
            m_to_encrypt.at(i) = tolower(m_to_encrypt.at(i));
        }else if (islower(m_to_encrypt.at(i))) {
            m_to_encrypt.at(i) = toupper(m_to_encrypt.at(i));
        }
        if (m_to_encrypt.at(i) == 'a') {
            m_to_encrypt.at(i) = 'z';
        }
        if (m_to_encrypt.at(i) == 'b') {
            m_to_encrypt.at(i) = 'x';
        }
        if (m_to_encrypt.at(i) == 'c') {
            m_to_encrypt.at(i) = 'y';
        }
        if (m_to_encrypt.at(i) == 'A') {
            m_to_encrypt.at(i) = '.';
        }
        if (m_to_encrypt.at(i) == 'B') {
            m_to_encrypt.at(i) = '/';
        }
        if (m_to_encrypt.at(i) == 'C') {
            m_to_encrypt.at(i) = '?';
        }
    }
    for (int i{ 0 }; i < m_to_encrypt.length(); ++i) {
        m_to_encrypt.at(i) = char((int)m_to_encrypt.at(i) + move_ascii);
    }
    e_message = m_to_encrypt;
    return e_message;
}

string Message_Decryptor(string message_to_decrypt, int move_ascii) {
    string m_to_decrypt = message_to_decrypt;
    for (int i{ 0 }; i < m_to_decrypt.length(); ++i) {
        m_to_decrypt.at(i) = char((int)m_to_decrypt.at(i) - move_ascii);
    }
    for (int i{ 0 }; i < m_to_decrypt.length(); ++i) {

        if (m_to_decrypt.at(i) == 'z') {
            m_to_decrypt.at(i) = 'a';
        }
        if (m_to_decrypt.at(i) == 'x') {
            m_to_decrypt.at(i) = 'b';
        }
        if (m_to_decrypt.at(i) == 'y') {
            m_to_decrypt.at(i) = 'c';
        }
        if (m_to_decrypt.at(i) == '.') {
            m_to_decrypt.at(i) = 'A';
        }
        if (m_to_decrypt.at(i) == '/') {
            m_to_decrypt.at(i) = 'B';
        }
        if (m_to_decrypt.at(i) == '?') {
            m_to_decrypt.at(i) = 'C';
        }
        if (isupper(m_to_decrypt.at(i))) {
            m_to_decrypt.at(i) = tolower(m_to_decrypt.at(i));
        }
        else if (islower(m_to_decrypt.at(i))) {
            m_to_decrypt.at(i) = toupper(m_to_decrypt.at(i));
        }

    }

    return m_to_decrypt;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
