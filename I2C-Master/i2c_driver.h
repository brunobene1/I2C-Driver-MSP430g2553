#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#define EPS_SLAVE 0x36

/**
 * \brief i2c setup
 */
void i2c_init();

/**
 * \brief starts the communication to write on a slave
 *
 * \param[in] slave_address slave address in hexadecimal
 */
void i2c_start_write_to_slave(int slave_address);

/**
 * \brief starts the communication to read from a slave
 *
 * \param[in] slave_address slave address in hexadecimal
 */
void i2c_start_read_from_slave(int slave_address);

/**
 * \brief write data to a slave
 *
 * \param[in] TxData buffer to send master data
 *
 * \param[in] numb_of_bytes number of bytes of the master message
 */
void i2c_write(const unsigned char TxData[], unsigned int numb_of_bytes);

/**
 * \brief read data from a slave
 *
 * \param[in] RxBuffer buffer to receive slave data
 *
 * \param[in] numb_of_bytes number of bytes of the slave message
 */
void i2c_read(volatile unsigned char RxBuffer[], unsigned int numb_of_bytes);

#endif /* I2C_DRIVER_H */
