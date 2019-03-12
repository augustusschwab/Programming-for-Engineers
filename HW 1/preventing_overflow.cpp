// Augustus Schwab
// HW 1 - ME EN 5250
// Due: 9/9/15
// Problem 2  - Preventing Overflow
// 
// PART A - 80s Game Development 
// A program that checks to make sure the boss in the videogame is not being healed. If healing is detected, 
// the code will output "No healing the boss to kill it!"
// Also, the boss' health will be printed everytime the player attempts to heal. There will be two cases,
//		1) When the healing is allowed because it doesn't cause and overflow.
//		2) When the healing is not allowed because it causes an overflow.
//
// PART B - Preventing Floating Point Overflow
// This program will check to see if casting a double to a float would cause and overflow to infinity. There 
// will be 2 different outputs:
//		1) If the number will overflow.
//		2) If the number won't overflow.


#include <bitset> // We use this to print numbers in binary format.
#include <iostream>
#include <limits> // We are going to use the name std::numeric_limits from this.
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	std::cout << "This is Part A of Problem 2: 80s Game Development" << '\n';
	std::cout << "" << '\n';

	short boss_health = 32000;
	
	while (boss_health > 0){													// This while loop checks to see if the boss_health
		boss_health += 400;														// is positive. If so it will add 400 to the health
		std::cout << "Healing Boss for = " << 400 << '\n';						// then print the health to the debugger screen.
		if (boss_health > 0){													// It won't add 400 or print the health if the health is
			std::cout << "Boss Health = " << boss_health << '\n';				// negative.
		}
	}
	while (boss_health < 0){													// This while loop will remove 400 from the boss_health
		boss_health -= 400;														// if the value is negative, as a result of adding 400 in
		std::cout << "No healing the boss to kill it!" << '\n';					// in the previous while loop. It will then print a warning	
		std::cout << "Boss Health = " << boss_health << '\n';					// to the debugger screen and print the previous positive
	}																			// value of the boss_health.
	
	// PART B

	std::cout << "" << '\n';
	std::cout << "" << '\n';
	std::cout << "This is Part B of Problem 2: Preventing Floating Point Overflow" << '\n';
	std::cout << "" << '\n';

	
	/*std::cout << std::scientific;
    std::cout << "Range for floats:"
		<< "\nMax float = " << std::numeric_limits<float>::max()
		<< "\nMin float = " << -std::numeric_limits<float>::max() << "\n";*/


	// The range of floats was found to be:
	//			Max = 3.402823e38
	//			Min = -3.402823e38
	// This was found from the commented block of code above and used to answer part B of problem 2.
	
	float f = 0;
	
	double d = 2e39;
	f = static_cast<float>(d);
	std::cout << d << " Will overflow a float." << "\n";

	d = 2e10;
	f = static_cast<float>(d);
	std::cout << d << " Won't overflow a float" <<", f = " << f << "\n";



	cin.get();

	return 0;
}
