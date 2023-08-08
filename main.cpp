/**************************************************
  Project: The Amazing RPG Character Generator
   Author: Jash Nguyen
  Purpose: Application File

 **************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

// Declare global variables
const string divider(40, '~');
string line;
vector<string> tempList;
vector<string> charTypes;
vector<string> charAttributes;
vector<string> charAttMins;
ifstream myFile;
string lastGeneratedCharacter;

// Declare functions
void displayHeader();
void runMenu();
void DisplayText();
vector<string> createLists(string yourFileName);
void generateCharacter();
void saveCharacterToFile();
void loadSavedCharacter();

int main() {
    int yourChoice;

    do {
        runMenu();
        cout << "Which option would you like (0-5): ";
        cin >> yourChoice;
        switch (yourChoice) {
            case 0: cout << "Thank you for testing this application \n"; break;
            case 1: DisplayText(); break;
            case 2: {
                charTypes = createLists("charTypes.txt");
                charAttributes = createLists("charAttributes.txt");
                charAttMins = createLists("charAttMins.txt");
                system("pause");
                system("cls");
                break;
                }
            case 3: generateCharacter(); break;
            case 4: saveCharacterToFile(); break;
            case 5: loadSavedCharacter(); break;
            default: cout << "Invalid Input \n"; break;
        }

    }
    while (yourChoice != 0);
    system("pause");
    system("cls");
    return 0;
}

/*******************************************************************
  User Defined functions
 *******************************************************************/

void displayHeader()
/* Display game's title */
{
    cout << divider << endl;
    cout << "The Amazing RPG Character Generator" << endl;
    cout << divider << endl;
}


void runMenu()
/* Display menu options to user*/
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
/* read data from text files and display data */
{
    system("cls");
    displayHeader();

    myFile.open("RPGAbout.txt");
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
    string output;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            output += str[i];
        }
    }
    return output;
}

vector<string> splitByComma(string lineToSplit) {
    /* split string of text by comma and remove
     white space if needed, return back the elements
     after splitting as a string vector */
    vector<string> cache;
    stringstream ss(lineToSplit);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ';');
        cache.push_back(removeSpace(substr));
    }
    return cache;
}


vector<string> createLists(string yourFileName) {
    /* Read data from text file and extract lines
     * into a vector string */
    string message = "Data loading from " + yourFileName;
    myFile.open(yourFileName);
    if (myFile.is_open())
    {
        getline(myFile, line);
        tempList = splitByComma(line);
        cout << message << endl;
        myFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
    return tempList;
}

void generateCharacter() {
    srand(time(NULL));
    string charType, charAttMin;
    int index = rand() % charTypes.size();

    charType = charTypes[index];
    charAttMin = charAttMins[index];
    lastGeneratedCharacter = charType + "\n";
    lastGeneratedCharacter += divider + "\n";
    for(int i = 0; i < charAttributes.size(); i ++) {
        int increment = rand()%5 + 1;
        int attMin = charAttMin[i] - '0';
        lastGeneratedCharacter += charAttributes[i] + " " + to_string(attMin + increment) + "\n";
    }
    lastGeneratedCharacter += '\n';
    cout << lastGeneratedCharacter;
    system("pause");
    system("cls");

}

void saveCharacterToFile() {
    char response;
    cout << lastGeneratedCharacter << "\n";
    cout << "Do you want to save this character? (y/n) ";
    cin >> response;
    if (response == 'y') {
        ofstream outputFile;
        outputFile.open("savedCharacters.txt",ofstream::app);
        outputFile << lastGeneratedCharacter;
        outputFile.close();
        cout << "This character is now saved.\n";
    }
    system("pause");
    system("cls");

}

void loadSavedCharacter() {
    ifstream readFile;
    readFile.open("savedCharacters.txt");
    if (readFile.is_open())
    {
        while ( getline (readFile,line) )
        {
            cout << line << '\n';
        }
        readFile.close();
    }

    else cout << "Unable to open file";
    system("pause");
    system("cls");


}