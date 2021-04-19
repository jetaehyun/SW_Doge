#include "../include/data_packet_light.h"

void Data_Packet_Light::create_packet() {

    pack_bits(packet, (uint32_t)light, 4);
    pack_bits(packet + 4, (uint32_t)this->user_id, 4);

    for(int i = 0; i < 10; i++) {

        pack_bits(packet + 8 + i, this->light_ids[i], 1);
        pack_bits(packet + 18 + i, this->light_status[i], 1);

    }

    pack_bits(packet + 29, this->disable_all_lights, 1);
    pack_bits(packet + 36, this->calculate_checksum(), 1);
    
}


void Data_Packet_Light::unpack_payload() {
    
    for(int i = 0; i < 10; i++) {

        uint8_t light_id = 0;
        uint8_t light_status = 0;

        unpack_bits(this->packet + PAYLOAD_OFFSET + i, light_id, 1);
        unpack_bits(this->packet + PAYLOAD_OFFSET + 10 + i, light_status, 1);

        this->light_ids[i] = light_id;
        this->light_status[i] = light_status;

    }

    unpack_bits(this->packet + 29, this->disable_all_lights, 1);
    
}


uint8_t *Data_Packet_Light::get_packet() {
    return this->packet;
}


void Data_Packet_Light::packet_details() {
    cout << (unsigned)this->user_id << endl;

    for(int i = 0; i < 10; i++) {
        cout << (unsigned) light_ids[i] << " ";
        cout << (unsigned) light_status[i] << " ;";
    }

    cout << endl;

    cout << (unsigned)this->disable_all_lights << endl;
}
