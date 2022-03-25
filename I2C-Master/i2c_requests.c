#include "i2c_requests.h"

unsigned char timercounter;
unsigned char msg[10] = { };
unsigned char store[10] = { };
unsigned char slave_msg[4] = { };
unsigned int crc8_var;
bool crc8_check_bool;
unsigned int i;
uint8_t slave_crc8;

void i2c_requests(int *current_request)
{
    switch(*current_request)
    {
        case 1: // Example of how a request should look like

        i2c_start_slave(EPS_SLAVE);             //Starts the communication with slave

        // ----- Master Message -----
        msg[0] = 0x30;                          //Random data
        crc8_var = crc8(msg, 1);                //Calculating crc8
        msg[1] = crc8_var;                      //Adding the crc8 value to the end of the message

        // ----- Sending Message -----
        i2c_write(msg, 2);                      //Sending master message

        default:
        *current_request = 0;
        break; //End of the requests

    }
}
