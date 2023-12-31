#include <string>
#include <iostream>
#include "audioOutput.h"

class output {     // The class
public:           // Access specifier
	output() {     // Constructor
	}

	audioOutput audioOutputInst;

	void equation(std::vector<int> numbers, uint number_count) {
		putout(std::to_string(numbers.at(0)));
		for (uint i = 1; i < number_count; i++) {
			if (numbers.at(i) > 0) {
				putout("+");
				putout(std::to_string(numbers.at(i)));
			} else {
				putout("-");
				putout(std::to_string(numbers.at(i) * -1));
			}
		}
	}

	void putout(std::string out) {
		for (int i = 0; i<100;i++)
			std::cout << std::endl;
		//std::cout << out;
		if (out == "1") {
			audioOutputInst.sendAudio_1();
		}
		if (out == "2") {
			audioOutputInst.sendAudio_2();
		}
		if (out == "3") {
			audioOutputInst.sendAudio_3();
		}
		if (out == "4") {
			audioOutputInst.sendAudio_4();
		}
		if (out == "5") {
			audioOutputInst.sendAudio_5();
		}
		if (out == "6") {
			audioOutputInst.sendAudio_6();
		}
		if (out == "7") {
			audioOutputInst.sendAudio_7();
		}
		if (out == "8") {
			audioOutputInst.sendAudio_8();
		}
		if (out == "9") {
			audioOutputInst.sendAudio_9();
		}
		if (out == "+") {
			audioOutputInst.sendAudio_plus();
		}
		if (out == "-") {
			audioOutputInst.sendAudio_minus();
		}
		if (out == "*") {
			audioOutputInst.sendAudio_mal();
		}
		if (out == ":") {
			audioOutputInst.sendAudio_geteilt();
		}
	}

	void audio() {
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
	}
};
