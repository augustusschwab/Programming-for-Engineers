// Augustus Schwab
// HW 2 - ME EN 5250
// Due: 9/16/15
// Problem 3 - Flip Flop
// 
// This program will model the behavior of a swithc over a 15 second interval. The switch is strange and 
// flips when the time is divisible by 3 and flops when the time is divsible by 5. The screen will output a flip
// when the switch flips and a flop with the switch flops, for the other times it will display the time value of the counter.	

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	int count = 0;
	bool flip = false;
	bool flop = false; 

	while (count < 100){
		if (count % 3 == 0 && count % 5 == 0){
			flip = true;
			flop = true;
		}

		if (flip == true && flop == true){
			std::cout << "FlipFlop" << "\n";
		}

		if (count % 3 == 0){
			flip = true;
		}

		if (flip == true && flop == false){
			std::cout << "Flip" << "\n";
		}
		
		if (count % 5 == 0){
			flop = true;
		}
		
		if (flop == true && flip == false){
			std::cout << "Flop" << "\n";
		}

		if (flip == false && flop == false){
			std::cout << count << "\n";
		}

		++count;
		flop = false;
		flip = false;
		
	}
	cin.get();

	return 0;

}