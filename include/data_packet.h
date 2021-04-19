#ifndef DATA_PACKET_H
#define DATA_PACKET_H

#include <iostream>
#include <cstdint>
#include <string>

#include "../include/data_manipulation.h"

#define NO_USER_SPECIFIED 0
#define PAYLOAD_SIZE 28
#define DATA_PACKET_SIZE 37
#define PAYLOAD_OFFSET 8

using std::cout;
using std::endl;
using namespace Data_Manipulation;

/*
    // 0
    // type
    // 4
    // user id
    // 8
    // payload
    // 36
    // checksum
    // 37

*/

class Data_Packet {
    public:

        Data_Packet(uint32_t user_id) { this->user_id = user_id; }

        Data_Packet() { this->user_id = NO_USER_SPECIFIED; }

        virtual ~Data_Packet() {}


        
        virtual void create_packet() = 0;
        virtual void unpack_payload() = 0;
        virtual uint8_t *get_packet() = 0;
        virtual void packet_details() = 0;
        bool unpack_packet(uint8_t *packet);


    protected:

        enum packet_type_e { light, testing };

        uint32_t user_id;
        uint8_t packet[DATA_PACKET_SIZE] = {0};

        uint8_t calculate_checksum();
        bool verify_checksum(uint8_t *packet);

};

#endif