#ifndef I2C_REQUESTS_H
#define I2C_REQUESTS_H

#include <msp430g2553.h>
#include "msp430g2xx3_uscib0_i2c_08.h"
#include "crc8.h"


/**
 * \brief All the i2c requests
 *
 * \param[in] current_request Current request variable
 */
void i2c_requests(int *current_request);


#endif /* I2C_REQUESTS_H */
