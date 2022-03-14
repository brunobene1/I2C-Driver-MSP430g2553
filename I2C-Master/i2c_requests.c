#include "i2c_requests.h"

unsigned char timercounter;
unsigned char msg[40] = { };
unsigned char store[40] = { };
unsigned char slave_msg[4] = { };
unsigned int crc8_var;
bool crc8_check_bool;
unsigned int i;
uint8_t slave_crc8;

void i2c_request_setup()
{
    WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

    BCSCTL1 = CALBC1_8MHZ;                    //Basic clock system control 1 set to 8Mhz

    DCOCTL = CALDCO_8MHZ;                     //Digitally controlled oscillator set to 8Mhz

    _EINT();                                  //Enable interrupts
}

void i2c_requests(int *current_request)
{
    switch(*current_request)
    {
        case 1:
        //---------------------------------------------------------------------------------
              TI_USCI_I2C_transmitinit(EPS, 0x12);      // init transmitting with USCI

              while ( TI_USCI_I2C_notready() );         // wait for bus to be free

              if ( TI_USCI_I2C_slave_present(EPS) )     // slave address may differ from
              {                                         // initialization
                // ----- Master Message -----

                msg[0] = 0x30;                          //Pedir para ler o ID da variavel (0xEEE2)

                crc8_var = crc8(msg, 1);                //Calculating crc8

                msg[1] = crc8_var;                      //Adding the crc8 value to the end of the message

                // ----- Master Message END -----

                // ------------------------------------

                // ----- Sending Master Message -----

                TI_USCI_I2C_transmitinit(EPS, 0x12);     // init transmitting with

                while ( TI_USCI_I2C_notready() );        // wait for bus to be free

                TI_USCI_I2C_transmit(2, msg);            // start transmitting

                // ----- Sending Master Message END -----

                // ------------------------------------

                // ----- Receiving Slave Message -----

                while ( TI_USCI_I2C_notready() );        // wait for bus to be free

                TI_USCI_I2C_receiveinit(EPS, 0x12);      // init receiving with USCI

                while ( TI_USCI_I2C_notready() );        // wait for bus to be free

                TI_USCI_I2C_receive(5, store);

                // ----- Receiving Slave Message END -----

                // ------------------------------------

                // ----- Checking slave msg and crc8 -----


                for(i=0; i<3; i++)
                {
                    slave_msg[i] = store[i];            //Transferring the slave msg from buffer "store" to the "slave_msg" array
                }

                slave_crc8 = store[5];                  //Transferring the crc8 from slave msg to the "slave_crc8" array

                crc8_check_bool = check_crc(slave_msg, 4, slave_crc8);   //Checking if the crc8 from slave is correct

                // ----- Checking slave msg and crc8 END -----
              }

              break;
        //---------------------------------------------------------------------------------

        default:
        //---------------------------------------------------------------------------------
            *current_request = 0;
            break; //End of the requests
        //---------------------------------------------------------------------------------

    }
}
