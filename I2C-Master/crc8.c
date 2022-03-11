#include "crc8.h"

uint8_t crc8(uint8_t *data, uint8_t len)
{
    uint8_t crc = INITIAL_VALUE;

    uint8_t i = 0U;
    for(i = 0; i < len; i++)
    {
        crc ^= data[i];

        uint8_t j = 0U;
        for (j = 0U; j < 8U; j++)
        {
            crc = (crc << 1) ^ ((crc & 0x80U) ? CRC8_POLYNOMIAL : 0U);
        }

        crc &= 0xFFU;
    }

    return crc;
}

bool check_crc(uint8_t *data, uint8_t len, uint8_t crc)
{
    return (crc == crc8(data, len));
}
