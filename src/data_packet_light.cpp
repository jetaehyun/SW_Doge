#include "../include/data_packet_light.h"

void Data_Packet_Light::create_packet() {

    Data_Manipulation::pack_bits(packet, light, 4);
    Data_Manipulation::pack_bits(packet + 4, this->user_id, 4);

    for(int i = 0; i < 10; i++) {
        Data_Manipulation::pack_bits(packet + 8 + i, this->light_ids.at(i), 1);

        Data_Manipulation::pack_bits(packet + 18 + i, this->light_status.at(i), 1);
    }

    Data_Manipulation::pack_bits(packet + 28, this->disable_all_lights, 1);
    Data_Manipulation::pack_bits(packet + 36, (uint32_t)100, 4);
    
}


void Data_Packet_Light::unpack_packet(uint8_t *packet) {
    
}


uint8_t *Data_Packet_Light::get_packet() {
    return this->packet;
}