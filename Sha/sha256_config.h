#ifndef Sha256_config_h
#define Sha256_config_h

#include <string.h>
#if  (defined(__linux) || defined(linux)) || defined(__ARDUINO_X86__)
	#if !defined(__ARDUINO_X86__)
		#define SHA256_LINUX
	#endif
	#define memcpy_P memcpy
	#undef PROGMEM
	#define PROGMEM __attribute__(( section(".progmem.data") ))
	#define pgm_read_dword(p) (*(p))
	#if defined(__ARDUINO_X86__)
		#include "Print.h"
	#endif	
#else
	#include <avr/io.h>
	#include <avr/pgmspace.h>
	#include "Print.h"
#endif

#include <inttypes.h>

#define HASH_LENGTH 32
#define BLOCK_LENGTH 64

#endif
