#ifndef DATA_MANIPULATION_H
#define DATA_MANIPULATION_H

#include <cstdint>

namespace Data_Manipulation {

    template<typename t>
    void pack_bits(uint8_t *payload, t data, int numberOfBytes);

    template<typename t>
    void unpack_bits(uint8_t *payload, t& data, int numberOfBytes);
}

#endif