#ifndef DATA_PACKET_LIGHT_H
#define DATA_PACKET_LIGHT_H

#include <iostream>
#include <cstdint>
#include <vector>

#include "data_packet.h"

using std::vector;
/*
    // 0
    // user profile
    // 4
    // light number
    // 5
    // on/off - 1 or 0
    // 6

*/

class Data_Packet_Light : public Data_Packet {

    public:

        Data_Packet_Light(uint32_t user_id, vector<uint8_t> light_ids, uint8_t light_status) : Data_Packet() { 
            this->user_id = user_id;
            this->light_ids = light_ids;
            this->light_status = light_status;
        }
        Data_Packet_Light() : Data_Packet() {}
        ~Data_Packet_Light() {}

        void create_payload();
        void unpack_payload();
        void pack_payload();

    private:

        uint32_t user_id;
        vector<uint8_t> light_ids;
        uint8_t light_status;

};

#endif