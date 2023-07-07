#include <SFML/Audio.hpp>

#include <chrono>
#include <thread>

class audioOutput {     // The class
public:           // Access specifier
	audioOutput() {     // Constructor
	}

	void setBufferAndPlay() {
		sound.setBuffer(buffer);
		sound.play();
		while (sound.getStatus() == 2) {
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	void sendAudio_1() {
		if (!buffer.loadFromFile("tts/1.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_2() {
		if (!buffer.loadFromFile("tts/2.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_3() {
		if (!buffer.loadFromFile("tts/3.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_4() {
		if (!buffer.loadFromFile("tts/4.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_5() {
		if (!buffer.loadFromFile("tts/5.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_6() {
		if (!buffer.loadFromFile("tts/6.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_7() {
		if (!buffer.loadFromFile("tts/7.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_8() {
		if (!buffer.loadFromFile("tts/8.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_9() {
		if (!buffer.loadFromFile("tts/9.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_plus() {
		if (!buffer.loadFromFile("tts/plus.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_minus() {
		if (!buffer.loadFromFile("tts/minus.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_mal() {
		if (!buffer.loadFromFile("tts/mal.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	void sendAudio_geteilt() {
		if (!buffer.loadFromFile("tts/geteilt.mp3.wav"))
			exit(-1);
		setBufferAndPlay();
	}
	sf::SoundBuffer buffer;
	sf::Sound sound;
};
