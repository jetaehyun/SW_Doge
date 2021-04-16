#ifndef DATA_PACKET_LIGHT_H
#define DATA_PACKET_LIGHT_H

#include <iostream>

#include "data_packet.h"

class Data_Packet_Light : public Data_Packet {

    public:

        Data_Packet_Light() : Data_Packet() { }
        ~Data_Packet_Light() {}

        void create_payload();
        void unpack_payload();
        void pack_payload();

    private:


};

#endif