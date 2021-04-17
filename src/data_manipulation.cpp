#include "../include/data_manipulation.h"

namespace Data_manipulation
{

    template<typename t>
    void pack_bits(uint8_t *payload, t data, int numberOfBytes) {
        
        for(int i = 0; i < numberOfBytes; i++) {
            payload[i] = data & 0xFF;
        }

    }

    template<typename t>
    void unpack_bits(uint8_t *payload, t& data, int numberOfBytes) {

        for(int i = 0; i < numberOfBytes; i++) {
            int bit_shift = i * 8;
            data = data | (payload[i] << bit_shift);
        }

    }

} // namespace Data_manipulation
