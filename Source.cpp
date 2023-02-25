// Eric Buchanan
// 2/25/2023


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;
string inputFile = "CS210_Project_Three_Input_File.txt";
string outputFile = "frequency.dat";
map<string, int> frequencyMap;
void displayMenu()
{
	cout << "*******************************************" << endl;
	cout << "****    Input item return frequency     ***" << endl;
	cout << "****   Return Frequency of all items    ***" << endl;
	cout << "****      Histogram of all items        ***" << endl;
	cout << "****              Exit                  ***" << endl;
	cout << "*******************************************" << endl;
}


void writeOutput()
{
	ofstream outFile(outputFile);
	if (!outFile.is_open()) 
	{
		cout << "Error opening file " << outputFile << endl;
		return;
	}
	for (const auto&entry : frequencyMap) 
	{
		outFile << entry.first << " " << entry.second << endl; // Writes the frequency data to the output file
	}
	outFile.close();
}

void readInput()
{
	ifstream inputFileS(inputFile); // input file stream

	if (!inputFileS.is_open())
	{
		cout << "Error opening file " << inputFile << endl;
		return;
	}
	string word;
	//Counts the number of times the word is counted
	while (inputFileS >> word)
	{
		frequencyMap[word]++;
	}
	inputFileS.close();
}


int main() 
{
	string choice;
	int menu_choice = 0; 
	readInput();
	writeOutput();
	// While loop for menu
	// option 1 - input item return frequency of item in file
	// option 2 - List of items on file and their frequency 
	// option 3 - histogram version of data from option 2
	// option 4 - exit

	while (menu_choice != 4) 
	{
		system("cls"); // Clears console for input
		displayMenu();
		
		
		cout << "Enter a menu choice: ";
		cin >> menu_choice;
		// If else tree for menu options
		if (menu_choice == 1) 
		{
			// Search for frequency of item in file
			cout << "Enter what item you want to search: ";
			cin >> choice;
			cout << "The frequency of " << choice << " is " << frequencyMap[choice] <<"." << endl;
			system("pause");
			
		}
		else if (menu_choice == 2)
		{
			// List of items on file and frequency
			for (const auto& entry : frequencyMap) {
				cout << entry.first << " " << entry.second << endl;
			}

			system("pause");
		}
		else if (menu_choice == 3) 
		{
			// Histogram version of Data
			for (const auto& entry : frequencyMap) {
				cout << entry.first << " ";
				for (int i = 0; i < entry.second; i++) {
					cout << "*";
				}
				cout << endl;
			}

			system("pause");

		}
		else if (menu_choice == 4)
		{
			//exit
			break;
		}
		else
		{
			// error checking input
			cout << "You put in an input that doesn't exist. Try again" << endl;
			system("pause");
		}
	

	}
	
	
	
return 0;

}

