#ifndef Sha256_h
#define Sha256_h

#include "sha256_config.h"

union _buffer {
  uint8_t b[BLOCK_LENGTH];
  uint32_t w[BLOCK_LENGTH/4];
};
union _state {
  uint8_t b[HASH_LENGTH];
  uint32_t w[HASH_LENGTH/4];
};

#if  (defined(__linux) || defined(linux)) && !defined(__ARDUINO_X86__)
class Sha256Class
#else
class Sha256Class : public Print
#endif
{
  public:
    void init(void);
    void initHmac(const uint8_t* secret, int secretLength);
    uint8_t* result(void);
    uint8_t* resultHmac(void);
    #if  (defined(__linux) || defined(linux)) && !defined(__ARDUINO_X86__)
	virtual size_t write(uint8_t);
	size_t write_L(const char *str);
	size_t write_L(const uint8_t *buffer, size_t size);
	size_t print(const char* str);
    #else
	virtual size_t write(uint8_t);
	using Print::write;
    #endif
  private:
    void pad();
    void addUncounted(uint8_t data);
    void hashBlock();
    uint32_t ror32(uint32_t number, uint8_t bits);
    _buffer buffer;
    uint8_t bufferOffset;
    _state state;
    uint32_t byteCount;
    uint8_t keyBuffer[BLOCK_LENGTH];
    uint8_t innerHash[HASH_LENGTH];
};
extern Sha256Class Sha256;

#endif
