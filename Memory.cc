/*
 * Memory.cc
 */

#include <fstream>
#include "Memory.h"

ROM::ROM(const char * filename) {
	std::fstream romfile;
	romfile.open(filename, std::ios::in | std::ios::ate);
	_contents.resize(romfile.tellg());
	romfile.seekg(0);
	romfile.read(reinterpret_cast<char*>(&_contents[0]), _contents.size());
	_address_mask = _contents.size() - 1;
}

void AddressSpace::write(unsigned address, uint8_t value, bool io) {
	if (io == true)
		_io.write(translate_mem_addr(address), value);
	else
		_ram.write(translate_mem_addr(address), value);
}

uint8_t AddressSpace::read(unsigned address, bool io) {

	if (io == true)
		return _io.read(translate_mem_addr(address));
	else {
		if (address < 32768)
			return _rom.read(translate_mem_addr(address));
		else
			return _ram.read(translate_mem_addr(address));

	}
}

uint32_t AddressSpace::translate_mem_addr(uint16_t address)
{
	uint32_t offset = address & 0x3fff;
	uint32_t real_address = offset;
	unsigned page = (address >> 14) & 0x03;
	if (page == 0) { // Это страница ПЗУ
		if (_io.rom_page() == 0)
			real_address |= 0x20000;
		else
			real_address |= 0x24000;
	}	else if (page == 1) { // Это страница видеопамяти
		if (_io.vid_page() == 0)
			real_address |= 0x14000;
		else
			real_address |= 0x1c000;
	}	else if (page == 2) { // это общая страница оперативки, банк 2
		real_address |= 0x08000;
	}	else {
		real_address |= _io.ram_page() << 14;
	}
	return real_address;
}
