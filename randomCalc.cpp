#include "randomNumberGen.h"
#include "audioOutput.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

//TODO: Export Output

void printVector(std::vector<int> vector){
	for (int n : vector)
		std::cout << n << ", ";
	std::cout << std::endl;
}

int main() {
	audioOutput audioOutputInst;
	audioOutputInst.sendAudio_1();
	audioOutputInst.sendAudio_2();
	audioOutputInst.sendAudio_3();
	audioOutputInst.sendAudio_4();
	audioOutputInst.sendAudio_5();
	audioOutputInst.sendAudio_6();
	audioOutputInst.sendAudio_7();
	audioOutputInst.sendAudio_8();
	audioOutputInst.sendAudio_9();
	audioOutputInst.sendAudio_plus();
	audioOutputInst.sendAudio_minus();
	audioOutputInst.sendAudio_mal();
	audioOutputInst.sendAudio_geteilt();

	uint number_max = 9;
	randomNumberGen randomNumberGenInst(number_max);

	uint tasks_count = 1;
	uint number_count = 40 * tasks_count;
	uint mathematical_operations_count = number_count - tasks_count;

	std::vector < int > numbers;
	while (tasks_count > 0) {
		int res = 0;
		for (uint i = 0; i < number_count; i++) {
			numbers.push_back(randomNumberGenInst.getNumber());
			res += numbers.at(i);
			if (res < 1 || numbers.at(i) == 0){
				numbers.clear();
				break;
			}
		}
		if (numbers.size() > 0) {
			tasks_count = 0;

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
