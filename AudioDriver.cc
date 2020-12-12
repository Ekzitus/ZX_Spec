/*
 * AudioDriver.cc
 */

#include <iostream>
#include "AudioDriver.h"

void real_audiodriver_cb(void * data, Uint8 * stream, int len)
{
	std::cout << "-------------real_audiodriver_cb-----------------" << std::endl;
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
	std::cout << "---------------_spec---------------" << std::endl;

	SDL_AudioSpec obt;

	_dev = SDL_OpenAudioDevice(nullptr, 0, &_spec, &obt, 0);
	std::cout << "---------------OpenAudioDevice---------------" << std::endl;


	SDL_PauseAudioDevice(_dev, 0);
	std::cout << "---------------UnPauseAudioDevice---------------" << std::endl;

	_level = 0;
}

AudioDriver::~AudioDriver()
{

	SDL_PauseAudioDevice(_dev, 1);
	std::cout << "-------------PauseAudioDevice-----------------" << std::endl;
	SDL_CloseAudioDevice(_dev);
	std::cout << "-------------CloseAudioDevice-----------------" << std::endl;

}

void AudioDriver::callback(short int * buffer, size_t len)
{
	std::cout << "-------------callback-----------------" << std::endl;
	std::cout << len << std::endl;
	for (size_t i = 0; i < len; i++){
		std::cout << _level << std::endl;
//		buffer[i] = stack.top(); //передает верхний элемент стека
		buffer[i] = _level;
//		stack.pop(); //удаляет верхний элемент стека
	}

}

void AudioDriver::addsample()
{
//	std::cout << _level << " 1" << std::endl;
	stack.push(_level);
	//записывает в стек
}


