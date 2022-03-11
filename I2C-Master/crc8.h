#ifndef CRC8_H
#define CRC8_H

#include "stdint.h"
#include "stdbool.h"

#define INITIAL_VALUE 0U
#define CRC8_POLYNOMIAL 0x07U

/**
 * \brief crc8 algorithm
 *
 * \param[in] data Holds the data
 *
 * \param[in] len length of the data
 */
uint8_t crc8(uint8_t *data, uint8_t len);

/**
 * \brief crc8 algorithm check
 *
 * \param[in] data Holds the data
 *
 * \param[in] len length of the data
 *
 * \param[in] crc received
 */
bool check_crc(uint8_t *data, uint8_t len, uint8_t crc);

#endif /* CRC8_H */
