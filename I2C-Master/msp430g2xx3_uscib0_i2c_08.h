#ifndef MSP430G2XX3_USCIB0_I2C_08_H
#define MSP430G2XX3_USCIB0_I2C_08_H

#define EPS_SLAVE 0x36

/**
 * \brief i2c setup
 */
void i2c_init();

/**
 * \brief starts the communication with a certain slave
 *
 * \param[in] slave_address slave address in hexadecimal
 */
void i2c_start_slave(int slave_address);

/**
 * \brief write data to a slave
 *
 * \param[in] TxData master data
 *
 * \param[in] numb_of_bytes number of bytes of the master message
 */
void i2c_write(const unsigned char TxData[], unsigned int numb_of_bytes);

#endif /* MSP430G2XX3_USCIB0_I2C_08_H */
