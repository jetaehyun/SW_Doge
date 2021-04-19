#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <array>

#include "../include/data_packet_light.h"
#include "../include/data_manipulation.h"

using std::cout;
using std::endl;
using std::array;
using namespace Data_Manipulation;

int main(int argc, const char *argv[]) {

    // uint8_t *test = new uint8_t[30];
    // uint16_t value = 15664;
    // uint16_t value_return = 0;

    // cout << value_return << endl;
    // pack_bits(test, value, 2);
    // unpack_bits(test, value_return, 2);

    // cout << value_return << endl;

    std::array<uint8_t,10> light_ids;
    std::array<uint8_t,10> light_status;

    for(uint8_t i = 0; i < 10; i++) {
        light_ids[i] = i;
        light_status[i] = 10 - i;
    }

    Data_Packet_Light dpl(1, light_ids, light_status, (uint8_t)3);
    dpl.packet_details();
    dpl.create_packet();

    Data_Packet_Light dpl2;

    dpl2.unpack_packet(dpl.get_packet());
    dpl2.unpack_payload();
    dpl2.packet_details();

    // delete[] test;


    return 0;
}