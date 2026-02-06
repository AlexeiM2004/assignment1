#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int transition_energy_calculator()
{
    // Ask user to enter atomic number
    cout << "Note, your input must be a positive whole integer greater than 0 and less than 173\n" << "Please specify your atomic number, z: ";
    int z;
    cin >> z;
    while ( z<1 || z>173 || cin.fail() ){
      cout << "\nYou have entered an invalid input, please try again,\n";
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Please specify your atomic number, z: ";
      cin >> z;
    }

  return 0;
}

int main()
{
    transition_energy_calculator();
    return 0;
}