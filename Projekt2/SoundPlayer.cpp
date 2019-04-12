#include "SoundPlayer.h"

SoundPlayer::SoundPlayer() {
	generateLowerSound();
	generateHigherSound();
	generateCrash();

	sound.stop();
}

SoundPlayer::~SoundPlayer() {
	delete[] lowerSoundSample;
	delete[] higherSoundSample;
	delete[] crashSample;
}

void SoundPlayer::generateLowerSound() {
	lowerSoundSample = new sf::Int16[SAMPLE_COUNT];
	bool isHigh = true;

	for (int i = 0; i < SAMPLE_COUNT; i++) {
		lowerSoundSample[i] =  isHigh ? SHRT_MAX : 0;

		if (i % 80 < 40)
			isHigh = true;
		else
			isHigh = false;
	}
}

void SoundPlayer::generateHigherSound() {
	higherSoundSample = new sf::Int16[SAMPLE_COUNT];
	bool isHigh = true;

	for (int i = 0; i < SAMPLE_COUNT; i++) {
		higherSoundSample[i] = isHigh ? SHRT_MAX : 0;

		if (i % 160 < 80)
			isHigh = true;
		else
			isHigh = false;
	}
}

void SoundPlayer::generateCrash() {
	crashSample = new sf::Int16[SAMPLE_COUNT];

	for (int i = 0; i < SAMPLE_COUNT; i++)
		crashSample[i] = rand() % SHRT_MAX;
}

void SoundPlayer::playLowerSound() {
	playFromBuffer(lowerSoundSample);
}

void SoundPlayer::playHigherSound() {
	playFromBuffer(higherSoundSample);
}

void SoundPlayer::playCrash() {
	playFromBuffer(crashSample);
}

void SoundPlayer::playFromBuffer(sf::Int16* soundSample) {
	soundBuffer.loadFromSamples(soundSample, SAMPLE_COUNT, 1, SAMPLE_RATE);
	sound.setBuffer(soundBuffer);
	sound.play();
}