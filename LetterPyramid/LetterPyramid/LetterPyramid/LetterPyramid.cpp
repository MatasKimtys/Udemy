/*
Author: Matas Kimtys
*/
#include <iostream>
#include <string>


using namespace std;
void ReversePrintPyramid(string letter);
void PrintPyramid(string letter);
string Reverse(string temp_string);

int main()
{
    srand(time(NULL));
    string letter{};
    getline(cin, letter);
    PrintPyramid(letter);

}

void PrintPyramid(string letter) {
    string temp_string, temp_string1, temp_string2;
    int final_line_size = letter.length() * 2 - 1;
    int current_line_size = 1;
    int white_spaces_to_add;
    for (int i{ 0 }; i < letter.length(); ++i) {
        //cout << "this is reverseString: " << temp_string_reversed;
        temp_string2 = temp_string + letter.at(i);
        temp_string1 = temp_string + letter.at(i) + Reverse(temp_string);
        temp_string = temp_string2;
        white_spaces_to_add = (final_line_size - current_line_size)/2;
        string temp_string_w_spaces(white_spaces_to_add, ' ');
        temp_string1 = temp_string_w_spaces + temp_string1 + temp_string_w_spaces;
        cout << temp_string1 << "\n";
        current_line_size += 2;
    }
    ReversePrintPyramid(temp_string1); //make diamond
}

void ReversePrintPyramid(string letter) {
    int temp = (letter.length() - 1) / 2 ;
    //cout << "Letter length: " << temp << ". Temp size: " << temp << endl;
    string reverse_letter;
    for (int i = 1; i < letter.length(); ++i) {
        letter.erase(temp);
        reverse_letter = letter;
        reverse_letter = reverse_letter.erase(reverse_letter.length() - 1);
        reverse_letter = Reverse(reverse_letter);
        letter = " " + letter + reverse_letter + " ";
        cout << letter << endl;
    }
}

string Reverse(string temp_string) {
    string temp_return_string;
    for (int k = (temp_string.length() - 1); k >= 0; --k) {
        temp_return_string += temp_string.at(k);
    }
    return temp_return_string;
}