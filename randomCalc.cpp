#include "randomNumberGen.h"
#include "output.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void printVector(std::vector<int> vector) {
	for (int n : vector)
		std::cout << n << ", ";
	std::cout << std::endl;
}

int singleTask(int number_count, int number_max) {
	randomNumberGen randomNumberGenInst(number_max);

	uint finished = 1;
	int res;
	while (finished > 0) {
		res = 0;
		std::vector<int> numbers;

		for (uint i = 0; i < number_count; i++) {
			numbers.push_back(randomNumberGenInst.getNumber());
			res += numbers.at(i);
			if (res < 1 || numbers.at(i) == 0) {
				numbers.clear();
				break;
			}
		}
		if (numbers.size() > 0) {
			finished = 0;

			output outputInst;
			outputInst.equation(numbers, number_count);
			std::cout << "=";

			int calc;
			std::cin >> calc;
			if (calc == res) {
				outputInst.putout(" ");
				std::cout << "Richtig!" << std::endl;
			} else {
				std::cout << "Falsch! Richtig wäre " << res << "." << std::endl;
				exit(1);
			}
		}
	}
	return res;
}

void loop(uint task_count, uint number_count, uint number_max) {
	int res = 0;
	for (uint i = 0; i < task_count; i++) {
		int task = singleTask(number_count, number_max);
		if ((res - task) > 0) {
			res = res - task;
		} else {
			res = res + task;
		}
	}
	std::cout << "=";

	int calc;
	std::cin >> calc;
	if (calc == res) {
		std::cout << "Richtig!" << std::endl;
	} else {
		std::cout << "Falsch! Richtig wäre " << res << "." << std::endl;
	}
}

int main(int argc, char *argv[]) {

	uint number_max = 9;

	uint number_count = 3;

	uint task_count = 2;

	uint loop_count = 2;

	if (argc > 1) {
		loop_count = atoi(argv[1]);
	}
	if (argc > 2) {
		number_count = atoi(argv[2]);
	}
	if (argc > 3) {
		task_count = atoi(argv[3]);
	}

	for (uint i = 0; i < loop_count; i++){
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		loop(task_count, number_count, number_max);
	}
}
