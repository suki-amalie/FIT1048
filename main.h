//
// Created by ADMIN on 15-Aug-23.
//

#ifndef THAOA1_MAIN_H
#define THAOA1_MAIN_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

// Declare global variables
const string divider(40, '~');
const string smalldivider(20, '~');
string line;

vector<string> tempList;
vector<string> charTypes;
vector<string> charAttributes;
vector<string> charAttMins;
ifstream FileToRead;
string lastGeneratedCharacter;

// Declare functions
void displayHeader();
void clearScreen();
void runMenu();
void DisplayText();
vector<string> createLists(string yourFileName);
void generateCharacter();
void saveCharacterToFile();
void loadSavedCharacter();
int main();

#endif //THAOA1_MAIN_H
