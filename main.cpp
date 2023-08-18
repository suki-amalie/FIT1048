/**************************************************
  Project: The Amazing RPG Character Generator
   Author: Thao Nguyen
  Purpose: Application File
  Task Oriented Project for Assigment 1
 **************************************************/


# include "main.h"

int main() {
    int yourChoice;
    // generate a new seed
    srand(unsigned (time(NULL)));
    do {
        // display menu options to user
        runMenu();
        cout << "Which option would you like (0-5): ";
        cin >> yourChoice;
        switch (yourChoice) {
            case 0: cout << "Thank you for testing this application.\n";clearScreen();break;
            case 1: DisplayText(); clearScreen(); break;
            case 2: {
                /* Read line from 3 different text files, split line
                 * by semicolon and store them into 3 separate variables
                 * as string vector */
                charTypes = createLists("charTypes.txt");
                charAttributes = createLists("charAttributes.txt");
                charAttMins = createLists("charAttMins.txt");
                clearScreen();
                break;
                }
            case 3: generateCharacter(); clearScreen(); break;
            case 4: saveCharacterToFile(); clearScreen(); break;
            case 5: loadSavedCharacter(); clearScreen(); break;
            default: cout << "Invalid Input\n"; clearScreen(); break;
        }

    } while (yourChoice != 0);
    return 0;
}

/*******************************************************************
  User Defined functions
 *******************************************************************/

void displayHeader()
//Display game's title
{
    cout << divider << endl;
    cout << "The Amazing RPG Character Generator" << endl;
    cout << divider << endl;
}

void clearScreen(){
    // Window
    system("pause");
    system("cls");
    // MAC or Linux
    /*
     system("read -n 1 -s -p "Press any key to continue"");
     system("clear");
     */
}

void runMenu()
//Display menu options to user
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
/* read data from text files and display data*/
{
    system("cls");
    displayHeader();

    FileToRead.open("RPGAbout.txt");
    if (FileToRead.is_open())
    {
        while (getline(FileToRead, line))
        {
            cout << line << '\n';
        }
        FileToRead.close();
    }
    else cout << "Unable to open file" << endl;
}


vector<string> splitLine(string lineToSplit) {
    /* split line of string by semicolon,
     * return back the elements after splitting
     * as a string vector */
    vector<string> cache;
    stringstream ss(lineToSplit);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ';');
        cache.push_back(substr);
    }
    return cache;
}


vector<string> createLists(string yourFileName) {
    /* Read line from text file, split words in line
     * by semicolon and store them into a vector string */
    string message = "Data loading from " + yourFileName;
    FileToRead.open(yourFileName);
    if (FileToRead.is_open())
    {
        getline(FileToRead, line);
        tempList = splitLine(line);
        cout << message << endl;
        FileToRead.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
    return tempList;
}

void generateCharacter() {
    string charType, charAttMin;

    // generate a random index to pick the character type
    int index = rand() % charTypes.size();

    charType = charTypes[index];
    // access the corresponding character's minimum attribute
    charAttMin = charAttMins[index];

    // store description about the new generated character
    lastGeneratedCharacter = "\n\t" + charType + "\n";
    lastGeneratedCharacter += "\t" + smalldivider + "\n";

    for(int i = 0; i < charAttributes.size(); i ++) {
        // add a random number from 0-5 to character's attribute
        int increment = rand()%6;
        // convert character's minimum attribute from char type to integer
        int attMin = charAttMin[i] - '0';
        lastGeneratedCharacter += "\t" + charAttributes[i] + " " + to_string(attMin + increment) + "\n";
    }
    // display character's stats to user
    cout <<  lastGeneratedCharacter << endl;
}

void saveCharacterToFile() {
    // take user's input and save the generated character to text file
    char response;
    // display the last generated character
    cout << lastGeneratedCharacter << "\n";
    cout << "Do you want to save this character? (y/n) ";
    cin >> response;
    if (tolower(response) == 'y') {
        ofstream outputFile;
        // append the last generated character to file
        outputFile.open("savedCharacters.txt",ios::app);
        if (outputFile.is_open()){
            outputFile << lastGeneratedCharacter;
            outputFile.close();
            cout << "This character is now saved.\n";
        } else
        {
            cout << "Unable to save character to file.\n";
        }
    }
}

void loadSavedCharacter() {
    // load all the saved generated character to screen
    FileToRead.open("savedCharacters.txt");
    if (FileToRead.is_open())
    {
        while ( getline (FileToRead,line) )
        {
            cout << line << endl;
        }
        FileToRead.close();
    }

    else {
        cout << "Unable to open file";
    }
    cout << "\n";
}