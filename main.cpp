#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
using namespace std;

string divider(40, '~');

void displayHeader()
{
    cout << divider << endl;
    cout << "The Amazing RPG Character Generator" << endl;
    cout << divider << endl;
}


void runMenu()
{
    displayHeader();
    cout << "[0] End Testing the Program" << endl;
    cout << "[1] Display \"About\" Information" << endl;
    cout << "[2] Read and store data from files" << endl;
    cout << "[3] Generate a random Character" << endl;
    cout << "[4] Save a Character to file" << endl;
    cout << "[5] Load saved Characters from file" << endl;
    cout << divider << endl;

}

void DisplayText()
{
    fstream myFile;
    string line;
    displayHeader();
    myFile.open("RPGAbout.txt", ios::in);
    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            cout << line << '\n';
        }
        myFile.close();
    }
    else cout << "Unable to open file" << endl;
    system("pause");
    system("cls");

}

string removeSpace(string str) {
    string output = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            output += str[i];
        }
    }
    return output;
}

vector<string> splitByComma(string line) {
    vector<string> cache;
    stringstream ss(line);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ';');
        cache.push_back(removeSpace(substr));
    }
    return cache;
}



void parseVec(vector<string> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

void createLists() {
    vector<string> lines, charTypes, charAtt, charAttMin;
    fstream readFile;
    string line;
    readFile.open("CharacterData.txt", ios::in);
    if (readFile.is_open())
    {
        while (!readFile.eof()) {
            getline(readFile, line);
            lines.push_back(line);
            cout << line << endl;
        }

        charTypes = splitByComma(lines[0]);
        parseVec(charTypes);
        charAtt = splitByComma(lines[1]);
        parseVec(charAtt);
        charAttMin = splitByComma(lines[2]);
        parseVec(charAttMin);
        readFile.close();
    }
    else cout << "Unable to open file" << endl;
    system("pause");
}
int main() {
    int yourChoice;

    do {
        runMenu();
        cout << "Which option would you like (0-5): ";
        cin >> yourChoice;
        switch (yourChoice) {
            case 0: cout << "Thank you for testing this application \n"; break;
            case 1: DisplayText(); break;
            case 2: createLists(); break;
            case 3: cout << "You have selected 3 \n"; break;
            case 4: cout << "You have selected 4 \n"; break;
            case 5: cout << "You have selected 5 \n"; break;
            default: cout << "Invalid Input \n"; break;
        }

    }
    while (yourChoice != 0) ;
    system("pause");
    system("cls");
    return 0;
}
