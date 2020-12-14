/*
 * AudioDriver.h
 */

#ifndef AUDIODRIVER_H_
#define AUDIODRIVER_H_


#include <SDL2/SDL.h>
#include <queue>

class AudioDriver
{
protected:
	SDL_AudioDeviceID _dev;
	SDL_AudioSpec _spec;
	std::queue<int> queue;
	short _level;
public:
	AudioDriver();
	~AudioDriver();

	void addsample();

	void callback(short * buffer, size_t len);

	void set_level(short level) { _level = level; }
};



#endif /* AUDIODRIVER_H_ */
