# I2C-Driver-MSP430g2553
Master and Slave Driver for MSP430g2553  

                                  /|\  /|\
                 MSP430G2xx3      10k  10k     MSP430G2xx3
                     slave         |    |        master
               -----------------   |    |  -----------------
             -|XIN  P1.6/UCB0SDA|<-|---+->|P1.6/UCB0SDA  XIN|-
              |                 |  |      |                 |
             -|XOUT             |  |      |             XOUT|-
              |     P1.7/UCB0SCL|<-+----->|P1.7/UCB0SCL     |
              |                 |         |                 |    
 
