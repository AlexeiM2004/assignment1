// Atomic Energy Transition Calculator
// Calculates photon transition energy using the Rydberg energy formula
// Alexei Maiorov, Student ID: [11022726]
// Date: [07/02/2026]

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <limits>

//Initialised global variable for multifunction use
const double rydberg_constant = 13.6; 
const double ev_to_joules_conversion = 1.602e-19; 
const double plancks_const = 6.626e-34;
const double speed_light = 299792458;

//Function aquires the parameters; atomic number, initial and final quantum number to then calculate the energy
//Int& means to pass by reference, this is useful for passing around the local variables between functions

void aquire_energy_parameters(int& atomic_number, int& initial_quantum_number, int& final_quantum_number)
{
  std::cout << "Welcome to the atomic energy transition calculator for hydrogen like atoms.\nNote, your input must be a positive whole integer greater than 0 and less than 173\n" << "Please specify your atomic number, z: ";
  std::cin >> atomic_number;
  while ( std::cin.fail() || atomic_number<1 || atomic_number>173 )
  {
    std::cout << "\nYou have entered an invalid input, please try again,\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please specify your atomic number, z: ";
    std::cin >> atomic_number;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "\nPlease enter your initial, n_i and final, n_f quantum numbers,\n";

  std::cout << "Initial quantum number n_i: ";
  std::cin >> initial_quantum_number;
  while ( std::cin.fail() || initial_quantum_number <= 0 )
  {
    std::cout << "\nYou have entered an invalid input, please try again,\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Initial quantum number n_i: ";
    std::cin >> initial_quantum_number;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Final quantum number n_f: ";
  std::cin >> final_quantum_number;
  while ( std::cin.fail() || final_quantum_number <= 0 || final_quantum_number == initial_quantum_number)
  {
    std::cout << "\nYou have entered an invalid input, please try again,\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Final quantum number n_f: ";
    std::cin >> final_quantum_number;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//Seperate function to calculate the photon's energy, by taking in the parameters aquired in the previous function

double photon_energy_calculator(int atomic_number, int initial_quantum_number, int final_quantum_number)
{
  double photon_energy = 0;
  //Photon energy is calculated using the Rydberg constant, the given atomic number, final and initial quantum numbers
  photon_energy = rydberg_constant * std::pow( atomic_number , 2 ) * ( 1.0 / (std::pow( final_quantum_number , 2)) - 1.0 / (std::pow( initial_quantum_number , 2 )));  

  return photon_energy;
}

//Seperate function to calculate the photon's wavelength

double photon_wavelength_calculator(double photon_energy)
{
  double photon_wavelength = plancks_const * speed_light / (std::abs(photon_energy) * ev_to_joules_conversion);

  return photon_wavelength;

}

//"Helper" function, to classify the energy transition type, used in the display energy units function

void classify_energy_transition(double photon_energy)
{
  if (photon_energy > 0)
  {
    std::cout << "\nEnergy was emitted in this transition.\n";
  }else
  {
    std::cout << "\nEnergy was absorbed in this transition.\n";
  }
}

//"Helper" function, to classify the wavelength in the electromagnetic spectrum, used in the display energy units function

void classify_wavelength(double photon_wavelength)
{
  if (photon_wavelength <= 1e-11)
  {
    std::cout << "Your wavelength is " << photon_wavelength << " m, This transitions falls in the gamma ray wavelength.\n";
  }else if(photon_wavelength < 1e-8)
  {
    std::cout << "Your wavelength is " << photon_wavelength << " m, This transitions falls in the x-ray wavelength.\n";
  }else if(photon_wavelength < 4e-7)
  {
    std::cout << "Your wavelength is " << photon_wavelength << " m, This transitions falls in the ultraviolet wavelength.\n";
  }else if(photon_wavelength < 7e-7)
  {
    std::cout << "Your wavelength is " << photon_wavelength << " m, This transitions falls in the visible wavelength.\n";
  }else if(photon_wavelength < 1e-3)
  {
    std::cout << "Your wavelength is " << photon_wavelength << " m, This transitions falls in the infrared wavelength.\n";
  }else if(photon_wavelength < 1)
  {
    std::cout << "Your wavelength is " << photon_wavelength << " m, This transitions falls in the microwave wavelength.\n";
  }else if(photon_wavelength > 1)
  {
    std::cout << "Your wavelength is " << photon_wavelength << " m, This transitions falls in the radiowave wavelength.\n";
  }
}

//Function gives user the choice for energy to be displayed in eV or Joules
//Tells the user if energy was emitted or absorbed depending on the sign of their photon energy

void display_energy_units(double photon_energy, double photon_wavelength)
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
      std::cout << "\nYour transition energy, in joules is " << std::abs(energy_joules) << " j\n";
      classify_energy_transition(photon_energy);
      classify_wavelength(photon_wavelength);
      break;

    }else if (units == "eV" || units == "e")
    {
      std::cout << "\nYour energy, in electron volts is " << std::abs(photon_energy) << " eV\n";
      classify_energy_transition(photon_energy);
      classify_wavelength(photon_wavelength);
      break;

    }else
    {
      std::cout << "\nInvalid input, please try again.\n";
    }
  }
}

//Main function calls both functions and gives the user a choice if they would like to re-use the calculator

int main()
{
  //Initialise variables to be passed around
  int atomic_number = 0;
  int initial_quantum_number = 0;
  int final_quantum_number = 0;
  double photon_energy = 0;
  double photon_wavelength = 0;
  //Call the functions with their variables passed into them
  aquire_energy_parameters(atomic_number, initial_quantum_number, final_quantum_number);
  photon_energy = photon_energy_calculator(atomic_number, initial_quantum_number, final_quantum_number);
  photon_wavelength = photon_wavelength_calculator(photon_energy);
  display_energy_units(photon_energy,photon_wavelength);
  while (true)
  {
    std::string retry;
    std::cout << "\nWould you like to use the energy transition calculator again?\nEnter 'Yes/yes' or 'No/no': ";
    std::cin >> retry;
    //If nested in the while loop
    if (retry == "Yes" || retry == "yes")
    {
      std::cout << "\n";
        aquire_energy_parameters(atomic_number, initial_quantum_number, final_quantum_number);
        photon_energy = photon_energy_calculator(atomic_number, initial_quantum_number, final_quantum_number);
        photon_wavelength = photon_wavelength_calculator(photon_energy);
        display_energy_units(photon_energy,photon_wavelength);
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