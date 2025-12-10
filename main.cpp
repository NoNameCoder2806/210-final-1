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
            // We insert the key into the map and make the count = 1
            airportTrafficCount.insert(make_pair(s, 1));
        }
    }

    // Display a header
    cout << "All airport traffic counts:" << endl;

    // Display all airports and the counts
    for (auto item : airportTrafficCount)
    {
        // Display the airport and the count
        cout << item.first << " " << item.second << endl;
    }

    // Create an integer variable to store the highest count
    int max = 0;

    // Loop through the map once and get the highest count
    for (auto item : airportTrafficCount)
    {
        // Update the count
        if (item.second > max)
        {
            max = item.second;
        }
    }

    // Loop through the map once again and display all the airports with the highest count

    return 0;
}