/**
 * \brief I2C-Driver-MSP430g2553
 *
 * \author Bruno Benedetti <brunobenedetti45@gmail.com>
 *
 * \version 2.5.0
 *
 * \date 10/03/2022
 *
 */


#include <msp430g2553.h>
#include "i2c_requests.h"

int current_i2c_request = 1;                //Starts at the first request

void main(void)
{

  i2c_init();                               //Setup function

  while(1)
  {
      i2c_requests(&current_i2c_request);   //i2c requests loop

      current_i2c_request++;                //Next request on the list
  }

}

