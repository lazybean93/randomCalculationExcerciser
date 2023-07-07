#include "randomNumberGen.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>

//TODO: Export random numbers
//TODO: Audio

void printVector(std::vector<int> vector){
	for (int n : vector)
		std::cout << n << ", ";
	std::cout << std::endl;
}

int main() {
	sf::SoundBuffer buffer;
	sf::Sound sound;
    if (!buffer.loadFromFile("tts/geteilt.mp3.wav"))
        return -1;
    sound.setBuffer(buffer);
    sound.play();
    while(sound.getStatus() == 2){
    	std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

	// Seed with a real random value, if available
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
