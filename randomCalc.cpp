#include "randomNumberGen.h"
#include "output.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

//TODO: Export Output

void printVector(std::vector<int> vector) {
	for (int n : vector)
		std::cout << n << ", ";
	std::cout << std::endl;
}

int main(int argc, char *argv[]) {

	uint number_max = 9;
	randomNumberGen randomNumberGenInst(number_max);

	uint tasks_count = 1;
	uint number_count = 3;

	if (argc > 1) {
		number_count = atoi(argv[1]);
	}

	std::vector<int> numbers;
	while (tasks_count > 0) {
		int res = 0;
		for (uint i = 0; i < number_count; i++) {
			numbers.push_back(randomNumberGenInst.getNumber());
			res += numbers.at(i);
			if (res < 1 || numbers.at(i) == 0) {
				numbers.clear();
				break;
			}
		}
		if (numbers.size() > 0) {
			tasks_count = 0;

			output outputInst;
			outputInst.equation(numbers, number_count);
			std::cout << "=";

			int calc;
			std::cin >> calc;
			if (calc == res) {
				std::cout << "Richtig!" << std::endl;
			} else {
				std::cout << "Falsch! Richtig wäre " << res << "." << std::endl;
			}
		}
	}
}
