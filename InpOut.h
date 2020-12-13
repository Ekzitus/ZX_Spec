/*
 * IO.h
 */

#ifndef INPOUT_H_
#define INPOUT_H_

#include <cstdint>
#include "AudioDriver.h"

class IO {
protected:
	uint8_t _port_fe { 0x00 };

	uint8_t _port_7ffd { 0x00 };

	uint8_t _key_matrix[8] { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };

	AudioDriver * _adrv;

public:
	IO(AudioDriver * drv) : _adrv(drv) {}

	virtual ~IO() = default;

	void write(unsigned address, uint8_t value);

	uint8_t read(unsigned address) const;

	uint8_t border() const {return _port_fe & 0x07;}

	unsigned ram_page() const { return _port_7ffd & 0x07; }
	unsigned vid_page() const { return (_port_7ffd >> 3) & 1; }
	unsigned rom_page() const { return (_port_7ffd >> 4) & 1; }

	void keydown(unsigned row, unsigned col);
	void keyup(unsigned row, unsigned col);


};

/*
class Port7FFD
{
protected:
	uint8_t _value;
public:
	virtual uint8_t read(uint16_t address) { return _value;}
	virtual void write(uint16_t address, uint8_t value) {
		if (((_value >> 5) & 1) == 0)
			_value = value;
	}
	unsigned ram_page() const { return _value & 0x07; }
	unsigned vid_page() const { return (_value >> 3) & 1; }
	unsigned rom_page() const { return (_value >> 4) & 1; }

	void reset() { _value = 0;}
};
*/

#endif /* INPOUT_H_ */
