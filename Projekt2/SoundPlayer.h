#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include <SFML/Audio.hpp>

class SoundPlayer {
public:
	SoundPlayer();
	~SoundPlayer();

	void playLowerSound();
	void playHigherSound();
	void playCrash();

private:
	const int SAMPLE_COUNT = 1000;
	const int SAMPLE_RATE = 16000;

	void generateLowerSound();
	void generateHigherSound();
	void generateCrash();

	void playFromBuffer(sf::Int16* soundSample);

	sf::Int16* lowerSoundSample;
	sf::Int16* higherSoundSample;
	sf::Int16* crashSample;

	sf::SoundBuffer soundBuffer;

	sf::Sound sound;
};

#endif