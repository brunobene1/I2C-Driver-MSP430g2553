#ifndef I2C_REQUESTS_H
#define I2C_REQUESTS_H

#include <msp430g2553.h>
#include "TI_USCI_I2C_master.h"
#include "crc8.h"


/**
 * \brief Setup function
 */
void i2c_request_setup();


/**
 * \brief All the i2c requests
 *
 * \param[in] current_request Current request variable
 */
void i2c_requests(int *current_request);


#endif /* I2C_REQUESTS_H */
