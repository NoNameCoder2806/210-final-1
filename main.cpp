// COMSC-210 | Final Exam 1 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// Constants
const string DATA_FILE = "210-final-1-FA25.txt";

// Main function
int main()
{
    // Create the map
    map<string, int> airportTrafficCount;

    // Create a file stream
    ifstream fin;
    fin.open(DATA_FILE);

    // Create a string to store the data
    string s;

    // Read the data file
    while (fin >> s)
    {
        // If the key exists
        if (airportTrafficCount.find(s) != airportTrafficCount.end())
        {
            // We increment its count on the map
            airportTrafficCount.at(s) += 1;
        }
        // Otherwise, the key doesn't exist
        else
        {
            // We insert the key into the map
            airportTrafficCount.insert(makepair<s, 0>);
        }
    }


    return 0;
}