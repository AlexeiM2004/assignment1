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
      //Begin to look at the quantum numbers
    cout << "\nPlease enter your initial, n_i and final, n_f quantum numbers,\n";
    double n_f,n_i;
    cout << "Initial quantum number n_i: ";
    cin >> n_i;
    //While loop for the initial quantum number
    while (n_i <= 0 || cin.fail() ){
      cout << "\nYou have entered an invalid input, please try again,\n";
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Initial quantum number n_i: ";
      cin >> n_i;
    }
    //While loop for the final quantum number
    cout << "Final quantum number n_f: ";
    cin >> n_f;
      while (n_f <= 0 || cin.fail() ){
      cout << "\nYou have entered an invalid input, please try again,\n";
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Final quantum number n_f: ";
      cin >> n_f;
    }
        //Photon energy calculation
    double photon_energy = 13.6 * pow( z , 2 ) * ( 1.0 / (pow( n_f , 2)) - 1.0 / (pow( n_i , 2 )) );  

    cout << "\nWould you like your transition energy to be in electron Volts , [eV] or Joules, [j]?\n";
    //While loop for unit conversion
    while (true){
      string units;
      cout << "Enter 'J/j' for Joules or 'eV/e' for Electron Volts: ";
      cin >> units;
      //If nested in the while loop
      if (units == "J" || units == "j"){
        double energy_joules = photon_energy * 1.602*pow(10,-19);
        cout << "\nYour transition energy, in joules is " << energy_joules << " j\n";
        break;

      }else if (units == "eV" || units == "e"){
        cout << "\nYour energy, in electron volts is " << photon_energy << " eV\n";
        break;

      }else{
        cout << "\nInvalid input, please try again.\n";
      }
    }
  return 0;
}

int main()
{
    transition_energy_calculator();
    return 0;
}