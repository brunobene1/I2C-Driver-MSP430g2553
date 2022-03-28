#ifndef I2C_REQUESTS_H
#define I2C_REQUESTS_H

#include <i2c_driver.h>
#include <msp430g2553.h>
#include "crc8.h"


/**
 * \brief All the i2c requests
 *
 * \param[in] current_request Current request variable
 */
void i2c_requests(int *current_request);


#endif /* I2C_REQUESTS_H */
