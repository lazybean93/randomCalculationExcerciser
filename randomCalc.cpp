#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

int main() {
	// Seed with a real random value, if available
	std::random_device r;
	uint tasks_count = 1;
	uint number_count = 4 * tasks_count;
	uint mathematical_operations_count = number_count - tasks_count;

	// Choose random numbers between 1 and 9
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 9);
	std::vector < uint > numbers;
	while (tasks_count > 0) {
		for (uint i = 0; i < number_count; i++) {
			numbers.push_back(uniform_dist(e1));
		}

		// print
		//for (uint i = 0; i < number_count; i++) {
		//	std::cout << "Randomly-chosen Number " << i << ": " << numbers.at(i)
		//			<< std::endl;
		//}

		// Choose Mathematical Operations
		// 1 = -
		// 2 = +
		std::uniform_int_distribution<int> uniform_dist2(1, 2);
		std::vector < uint > mathematical_operations_uint;
		for (uint i = 0; i < mathematical_operations_count; i++) {
			mathematical_operations_uint.push_back(uniform_dist2(e1));
		}

		// print
		//for (uint i = 0; i < mathematical_operations_count; i++) {
		//	std::cout << "Randomly-chosen Mathematical Operation " << i << ": "
		//			<< mathematical_operations_uint.at(i) << std::endl;
		//}

		// Check for Overflow
		bool overflow = false;
		uint res = numbers.at(0);
		for (uint j = 1; j < number_count; j++) {
			//std::cout << res;
			if (mathematical_operations_uint.at(j - 1) == 1) {
				//std::cout << "-";
				res = res - numbers.at(j);
				if (res > (uint)(0 - 9)) {
					//std::cout << "Overflow" << std::endl;
					overflow = true;
					break;
				}
			} else {
				//std::cout << "+";
				res = res + numbers.at(j);
			}
			//std::cout << numbers.at(j) << "=" << res << std::endl;
		}
		if (!overflow) {
			tasks_count = 0;
			std::cout << numbers.at(0);
			for (uint i = 1; i < number_count; i++) {
				if (mathematical_operations_uint.at(i - 1) == 1) {
					std::cout << "-";
				} else {
					std::cout << "+";
				}
				std::cout << numbers.at(i);
			}
			std::cout << "=";

			int calc;
			std::cin >> calc;
			if (calc == res) {
				std::cout << "Richtig!" << std::endl;
			} else {
				std::cout << "Falsch! Richtig wäre " << res
						<< "." << std::endl;
			}
		}
	}
}
