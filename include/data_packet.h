#ifndef DATA_PACKET_H
#define DATA_PACKET_H

#include <iostream>
#include <cstdint>
#include <string>

/*
    // 0
    // type
    // 4
    // user profile
    // 8
    // payload
    // 36
    // checksum
    // 40

*/

class Data_Packet {
    public:

        Data_Packet() {}
        virtual ~Data_Packet() {}

        virtual void create_payload() = 0;
        virtual void unpack_payload() = 0;
        virtual void pack_payload() = 0;


    protected:

        enum packet_type_e { light, testing };

        typedef struct _data_packet_t {
            uint32_t type;
            uint32_t user_id;
            uint8_t payload[28];
            uint32_t checksum;
        } data_packet_t;

};

#endif