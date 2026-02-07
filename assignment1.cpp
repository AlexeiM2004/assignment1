// Atomic Energy Transition Calculator
// Calculates photon transition energy using the Rydberg energy formula
// Alexei Maiorov, Student ID: [11022726]
// Date: [07/02/2026]

#include <iostream>
#include <string>
#include <cmath>

double photon_energy = 0.0; //Initialised global variable for multifunction use
const double rydberg_constant = 13.6; 
const double ev_to_joules_conversion = 1.602e-19; 

//Function aquires the parameters; atomic number, initial and final quantum number to then calculate the energy

int calculate_transition_energy()
{
  std::cout << "Welcome to the atomic energy transition calculator for hydrogen like atoms.\nNote, your input must be a positive whole integer greater than 0 and less than 173\n" << "Please specify your atomic number, z: ";
  int atomic_number;
  std::cin >> atomic_number;
  while ( atomic_number<1 || atomic_number>173 || std::cin.fail() )
  {
    std::cout << "\nYou have entered an invalid input, please try again,\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Please specify your atomic number, z: ";
    std::cin >> atomic_number;
  }
  std::cout << "\nPlease enter your initial, n_i and final, n_f quantum numbers,\n";
  double final_quantum_number,initial_quantum_number;
  std::cout << "Initial quantum number n_i: ";
  std::cin >> initial_quantum_number;
  while (initial_quantum_number <= 0 || std::cin.fail() )
  {
    std::cout << "\nYou have entered an invalid input, please try again,\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Initial quantum number n_i: ";
    std::cin >> initial_quantum_number;
  }
  std::cout << "Final quantum number n_f: ";
  std::cin >> final_quantum_number;
  while (final_quantum_number <= 0 || std::cin.fail() )
  {
    std::cout << "\nYou have entered an invalid input, please try again,\n";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout << "Final quantum number n_f: ";
    std::cin >> final_quantum_number;
  }
  //Photon energy is calculated using the Rydberg constant, the given atomic number, final and initial quantum numbers
  photon_energy = rydberg_constant * std::pow( atomic_number , 2 ) * ( 1.0 / (std::pow( final_quantum_number , 2)) - 1.0 / (std::pow( initial_quantum_number , 2 )) );  
  
  return 0;
}

//Function gives user the choice for energy to be displayed in eV or Joules

int display_energy_units()
{
  std::cout << "\nWould you like your transition energy to be in electron Volts , [eV] or Joules, [j]?\n";
  while (true)
  {
    std::string units;
    std::cout << "Enter 'J/j' for Joules or 'eV/e' for Electron Volts: ";
    std::cin >> units;
    if (units == "J" || units == "j")
    {
      double energy_joules = photon_energy * ev_to_joules_conversion;
      std::cout << "\nYour transition energy, in joules is " << energy_joules << " j\n";
      break;

    }else if (units == "eV" || units == "e")
    {
      std::cout << "\nYour energy, in electron volts is " << photon_energy << " eV\n";
      break;

    }else
    {
      std::cout << "\nInvalid input, please try again.\n";
    }
  }

  return 0;
}

//Main function calls both functions and gives the user a choice if they would like to re-use the calculator

int main()
{
  calculate_transition_energy();
  display_energy_units();
  while (true)
  {
    std::string retry;
    std::cout << "\nWould you like to use the energy transition calculator again?\nEnter 'Yes/yes' or 'No/no': ";
    std::cin >> retry;
    //If nested in the while loop
    if (retry == "Yes" || retry == "yes")
    {
      std::cout << "\n";
      calculate_transition_energy();
      display_energy_units();
    }else if (retry == "No" || retry == "no")
    {
      std::cout << "\nThank you for using the energy transition calculator, have a nice day.";
      return 0;
    }else
    {
      std::cout << "\nInvalid input, please try again.\n";
    }
  }

  return 0;
}