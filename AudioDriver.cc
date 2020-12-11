/*
 * AudioDriver.cc
 */

#include <iostream>
#include "AudioDriver.h"

void real_audiodriver_cb(void * data, Uint8 * stream, int len)
{
	std::cout << stream << std::endl;
	reinterpret_cast<AudioDriver*>(data)->callback(
			reinterpret_cast<short *>(stream),
			size_t(len));
}

AudioDriver::AudioDriver()
{
	_spec.callback = real_audiodriver_cb;
	_spec.userdata = this;
	_spec.channels = 1;
	_spec.format = AUDIO_S16;
	_spec.samples = 128;
	_spec.freq =  44100;

	SDL_AudioSpec obt;

	_dev = SDL_OpenAudioDevice(nullptr, 0, &_spec, &obt, 0);
	SDL_PauseAudioDevice(0, 0);

	_level = 0;
}

AudioDriver::~AudioDriver()
{
	SDL_PauseAudioDevice(0, 1);
	SDL_CloseAudioDevice(_dev);
}

void AudioDriver::callback(short int * buffer, size_t len)
{
	for (size_t i = 0; i < len; i++){
		buffer[i] = stack.top(); //передает верхний элемент стека
		stack.pop(); //удаляет верхний элемент стека
	}

}

void AudioDriver::addsample()
{
	std::cout << _level << std::endl;
	stack.push(_level);
	//записывает в стек
}


