#ifndef DATA_PACKET_LIGHT_H
#define DATA_PACKET_LIGHT_H

#include <iostream>
#include <cstdint>
#include <array>

#include "data_packet.h"
#include "data_manipulation.h"

using namespace Data_Manipulation;
using std::cout;
using std::endl;
using std::array;

/*
    // 0
    // light numbers
    // 10
    // on/off - 0 or 1
    // 20
    // all lights on/off
        - 0 off
        - 1 on
        - 3 nothing
    // 21
*/

class Data_Packet_Light : public Data_Packet {

    public:

        Data_Packet_Light(uint32_t user_id, array<uint8_t, 10> light_ids, array<uint8_t, 10> light_status, uint8_t disable_all_lights)
        : Data_Packet(user_id) { 
            this->light_ids = light_ids;
            this->light_status = light_status;
            this->disable_all_lights = disable_all_lights;
        }

        Data_Packet_Light() : Data_Packet() {}

        ~Data_Packet_Light() {}



        void create_packet();
        void unpack_payload();
        void packet_details();
        uint8_t *get_packet();


    private:

        std::array<uint8_t,10> light_ids = {0};
        std::array<uint8_t,10> light_status = {0};
        uint8_t disable_all_lights = 0;

};

#endif