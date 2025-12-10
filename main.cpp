// COMSC-210 | Final Exam 1 | Dat Hoang Vien
// IDE used: Visual Studio Code

#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

const string DATA_FILE = "210-final-1-FA25.txt";

void displayRange(const map<string, int>& m, int low, int high);

int main()
{
    // Milestone 1
    map<string, int> airportTrafficCount;

    ifstream fin;
    fin.open(DATA_FILE);

    string s;

    while (fin >> s)
    {
        if (airportTrafficCount.find(s) != airportTrafficCount.end())
        {
            airportTrafficCount.at(s) += 1;
        }
        else
        {
            airportTrafficCount.insert(make_pair(s, 1));
        }
    }

    cout << "All airport traffic counts:" << endl;

    for (auto item : airportTrafficCount)
    {
        cout << item.first << " " << item.second << endl;
    }

    cout << endl;

    // Milestone 2
    int max = 0;

    for (auto item : airportTrafficCount)
    {
        if (item.second > max)
        {
            max = item.second;
        }
    }

    cout << "Busiest airport(s) with count " << max << ":" << endl;

    for (auto item : airportTrafficCount)
    {
        if (item.second == max)
        {
            cout << item.first << " " << item.second << endl;
        }
    }

    cout << endl;

    // Milestone 3
    displayRange(airportTrafficCount, 5, 8);
    displayRange(airportTrafficCount, 9, 12);

    return 0;
}

// Milestone 3
void displayRange(const map<string, int>& airport, int low, int high)
{
    cout << "Airports with traffic in range [" << low << ", " << high << "]:" << endl;

    for (auto item : airport)
    {
        if (item.second >= low && item.second <= high)
        {
            cout << item.first << " " << item.second << endl;
        }
    }

    cout << endl;
}