#include "../include/data_packet.h"

uint8_t Data_Packet::calculate_checksum() {
    
    uint8_t checksum = 0;

    for(int i = 0; i < DATA_PACKET_SIZE - 1; i++) {
        checksum += this->packet[i];
    }

    // cout << ~checksum + 1 << endl;
    return ~checksum + 1;
}


bool Data_Packet::verify_checksum(uint8_t *packet) {

    uint8_t checksum = 0;

    for(int i = 0; i < DATA_PACKET_SIZE; i++) {
        checksum += packet[i];
    }

    if(checksum == 0) return true;

    return false;
}


bool Data_Packet::unpack_packet(uint8_t *packet) {

    if(!this->verify_checksum(packet)) {
        cout << "[Data Packet]: Data is corrupted..." << endl;
        return false;
    } 

    unpack_bits(packet + 4, this->user_id, 4);

    unpack_bits_array(packet, this->packet, 4);
    unpack_bits_array(packet + 4, this->packet + 4, 4);
    unpack_bits_array(packet + 8, this->packet + 8, 28);
    unpack_bits(packet + 36, this->packet[36], 1);

    return true;

}
