#ifndef DATA_MANIPULATION_H
#define DATA_MANIPULATION_H

#include <cstdint>
#include <iostream>

namespace Data_Manipulation {

    template<typename t>
    inline void pack_bits(uint8_t *bytes, t data, int numberOfBytes) {
        
        for(int i = 0; i < numberOfBytes; i++) {
            int bit_shift = i * 8;
            bytes[i] = (data >> bit_shift) & 0xFF;
        }

    }


    template<typename t>
    inline void unpack_bits(uint8_t *bytes, t& data, int numberOfBytes) {

        for(int i = 0; i < numberOfBytes; i++) {
            int bit_shift = i * 8;
            data |= (bytes[i] << bit_shift);
        }

    }


    inline void pack_bits_array(uint8_t *bytes, uint8_t *data, int numberOfBytes) {

        for(int i = 0; i < numberOfBytes; i++) {
            bytes[i] = data[i] & 0xFF;
        }

    }


    inline void unpack_bits_array(uint8_t *bytes, uint8_t *data, int numberOfBytes) {

        for(int i = 0; i < numberOfBytes; i++) {
            data[i] = bytes[i];
        }

    }

    
}

#endif