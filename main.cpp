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

// Functions
void displayRange(const map<string, int>& m, int low, int high);

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

    // Enter a new line
    cout << endl;

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

    // Display a message
    cout << "Busiest airport(s) with count " << max << ":" << endl;

    // Loop through the map once again and display all the airports with the highest count
    for (auto item : airportTrafficCount)
    {
        // Compare the count
        if (item.second == max)
        {
            // Display the airport and the count
            cout << item.first << " " << item.second << endl;
        }
    }

    // Create a low and high variable for the range
    int low = 0;
    int high = 0;

    return 0;
}

// Function implementations
/*
    displayRange()
    Display the airports whose traffic counts fall within a specified inclusive range [low, high]
    Arguments:
        - airport: the map that stores the airport code and the counts
        - low: the lower / smaller number of the range
        - high: the upper / larger number of the range
*/
void displayRange(const map<string, int>& airport, int low, int high)
{
    // Display a message
    cout << "Airports with traffic in range [" << low << 
    // Loop through the  map
    for (auto item : airport)
    {
        // Check whether the count falls within the range
        if (item.second >= low && item.second <= high)
        {
            // Display the airport and the count
            cout << item.first << " " << item.second << endl;
        }
    }
}