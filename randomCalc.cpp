#include "randomNumberGen.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

//TODO: Export random numbers
//TODO: Audio

void printVector(std::vector<int> vector){
	for (int n : vector)
		std::cout << n << ", ";
	std::cout << std::endl;
}

int main() {
	// Seed with a real random value, if available
	uint number_max = 9;
	randomNumberGen randomNumberGenInst(number_max);

	uint tasks_count = 1;
	uint number_count = 4 * tasks_count;
	uint mathematical_operations_count = number_count - tasks_count;

	std::vector < int > numbers;
	while (tasks_count > 0) {
		//first number must be positive
		//get first number
		int res = randomNumberGenInst.getNumber();
		//negative number = try again
		if (res < 0){
			continue;
		}
		numbers.push_back(res);
		for (uint i = 1; i < number_count; i++) {
			numbers.push_back(randomNumberGenInst.getNumber());
			res += numbers.at(i);
			if (res < 0){
				numbers.clear();
				break;
			}
		}
		if (numbers.size() > 0) {
			tasks_count = 0;

			// print
			for (uint i = 0; i < number_count; i++) {
				std::cout << "Randomly-chosen Number " << i << ": " << numbers.at(i)
						<< std::endl;
			}

			std::cout << numbers.at(0);
			for (uint i = 1; i < number_count; i++) {
				if (numbers.at(i)>0){
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
