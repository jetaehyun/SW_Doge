#ifndef DATA_PACKET_H
#define DATA_PACKET_H

#include <iostream>

class Data_Packet {
    public:

        Data_Packet() {}
        virtual ~Data_Packet() {}

        virtual void create_payload() = 0;
        virtual void unpack_payload() = 0;
        virtual void pack_payload() = 0;

    protected:
};

#endif