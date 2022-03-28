#include "i2c_requests.h"


unsigned char TxBuffer[10];                 // Tx buffer
volatile unsigned char RxBuffer[128];       // Rx buffer, allocate 128 byte of RAM
unsigned int crc8_var;
bool crc8_check_bool;
uint8_t slave_crc8;
unsigned int i;
unsigned char slave_msg[4];
//unsigned char timercounter;

void i2c_requests(int *current_request)
{
    switch(*current_request)
    {
        case 1: // Example of how a request should look like

        i2c_start_write_to_slave(EPS_SLAVE);         //Starts the communication to write on the slave

        // ----- Master Message -----
        TxBuffer[0] = 0x30;                          //Random data
        crc8_var = crc8(TxBuffer, 1);                //Calculating crc8
        TxBuffer[1] = crc8_var;                      //Adding the crc8 value to the end of the message

        // ----- Sending Message -----
        i2c_write(TxBuffer, 2);                      //Sending master message

        // ----- Reading Message -----
        i2c_start_read_from_slave(EPS_SLAVE);        //Starts the communication to read from the slave
        i2c_read(RxBuffer, 5);

        // ----- crc8 -----
        for(i =0; i < 4; i++)
        {
            slave_msg[i] = RxBuffer[i];
        }

        slave_crc8 = RxBuffer[5];
        crc8_check_bool = check_crc(slave_msg, 4, slave_crc8); //Checks if the crc8 is correct

        break;

        default:
        *current_request = 0;
        break; //End of the requests

    }
}
